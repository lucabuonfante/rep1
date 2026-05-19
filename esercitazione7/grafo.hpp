/* costruisco una mappa, in cui le chiavi sono i nodi. ogni elemento è un set e contiene i nodi vicini al nodo chiave*/
#pragma once
#include <set>
#include <map>
#include <list>
#include "edges.hpp"
#include<vector>
#include<algorithm>
#include<list>

template <typename T>
class grafo {
    private:
    std::map<T, std::set<T>> nodi_;
    std::vector<unidir_edge<T>> archi_;

    public:
    
    grafo() { //costruttore di default
        nodi_= std::map<T, std::set<T>>();
        archi_ = std::vector<unidir_edge<T>>(); /*vettore vuoto, ma deve essere inizializzato con degli archi in qualche modo,
        per questo serve il costruttore di default degli archi*/
    }

    /*costruttore user defined 1: riceve una mappa che ha come indici i nodi
    e come elementi set vuoti e un vettore di archi. completa i set con i vicini*/

    grafo (std::map<T, std::set<T>>& m, std::vector<unidir_edge<T>>& a) {
        
        for (const unidir_edge<T>& arco : a) { /*per ogni arco*/
            
            /*prendo i due estremi dell'arco*/
            const T & f=arco.from();
            const T & t=arco.to();
            /*metto t tra i vicini di f*/
            std::set<T> & vicinif= m.at(f); 
            vicinif.insert(t);
            /*metto f tra i vicini di t*/
            std::set<T> & vicinit=m.at(t);
            vicinit.insert(f);
        }
        nodi_=m;
        std::sort(a.begin(),a.end());
        archi_=a; /*almeno siamo sicuri che a sia ordinato*/

    }
    
    std::vector<unidir_edge<T>> genera_archi(const std::map<T, std::set<T>>& nodi) const {
        int num_archi=0;
        for (const auto& [nodo, vicini] : nodi) { /*O(n)*/ 
            num_archi= num_archi + vicini.size(); /*il numero degli archi è la metà
            della somma dei vicini di ogni nodo VEDI SE E' GIUSTO. nel vettore li salvo tutti duplicati */
        }
        num_archi=num_archi/2;
        
        std::vector<unidir_edge<T>> ed(num_archi);
        int ind=0;
        /*O(n^2)*/
        for (const auto& [nodo, vicini] : nodi) { /*ciclo sugli elementi del grafo*/
            for (const T& v : vicini) { /*ciclo sugli elementi del set "vicini"*/
                if (nodo<v) { /*in questo modo sono sicuroo di non creare duplicati*/
                unidir_edge<T> e=unidir_edge(nodo,v); /*uso il costruttore di unidir_edge user defined*/
                ed[ind]=e;
                ind =ind+1;
                }
                
            }
        }
        
        std::sort(ed.begin(),ed.end()); /*ordino il vettore. il metodo userà il criterio
        di ordinamento definito nella classe edges (speriamo, altrimenti fallo manuale)*/

        return ed;
    }


    /*costruttore user defined 2: riceve una mappa di set e costruisce da solo il vettore degli archi*/
    grafo (const std::map<T, std::set<T>>& n) {
        nodi_=n;
        archi_=genera_archi(n);
    }

    /*copia*/
    grafo(const grafo& g) {
    nodi_ = g.nodi();
    archi_ = g.archi();
    }

    /*due costrutti per tirare fuori nodi e archi: */
    const std::map<T, std::set<T>>& nodi() const {
        return nodi_;
    }
    
    const std::vector<unidir_edge<T>>& archi() const {
        return archi_;
    }

    /*prende una chiave e restituisce il set*/
    const std::set<T>& vicini ( const T& chiave) const {
        return nodi_.at(chiave); /*usiamo at così se la chiave non c'è
        restituisce un'eccezione*/
    }

    /*estrae tutte le chiavi dalla mappa e ci fa un set, perché poi devo confrontarlo,
    quindi usare una lista sarebbe scomodo*/
    std::list<T> all_nodes() const {
        
        std::list<T> lista_nodi;
        
        for (const auto& [nodo, vicini] : nodi_) {
            lista_nodi.push_front(nodo);
        }
        return lista_nodi;
    }

    std::vector<unidir_edge<T>> all_edges() const {
        return archi_;
    }

    int edge_number (const unidir_edge<T>& ed) const {
        int ind=0; 
        int s=archi_.size();
        while (ind<s){        
            if (archi_[ind]==ed) {
                return ind;
            }
            else {
                ind=ind+1;
            }
        }
        return -1; /* se non trovo l'arco*/
    }

    unidir_edge<T> edge_at(int n) const {
        return archi_[n];
    }

    grafo& add_edge (const unidir_edge<T> & ed) {

        T f=ed.from();
        T t= ed.to();
        nodi_[f].insert(t); /*se f sta nel grafo, aggiunge t al set che f indica,
        mentre se f non sta nel grafo aggiunge un nodo f e nel relativo set ci mette t*/
        nodi_[t].insert(f);
        archi_=genera_archi(nodi_);    
        return *this;
    }


    /*qui uso solo i nodi, poi gli archi li rifaccio*/
    grafo& operator-=(const grafo& g2) {
        /*non posso eliminare gli elementi con erase mentre ci sto facendo un ciclo sopra*/
        for (auto& [nodo, vicini] : nodi_) { /*per ogni nodo, considero i vicini nel grafo 1*/
            std::list<T> l; /*conterrà i nodi da eliminare*/
            for (auto& n : vicini) {
                if (g2.nodi().contains(nodo)==true) { /*se il nodo è i g2*/
                    if (g2.vicini(nodo).contains(n)==true) { /*e se i suoi vicini contengono n*/
                        l.push_back(n); /*mettiamo n nella lista dei nodi da eliminare*/
                    } 
                }
                
            }
            for (auto& y : l) {
                vicini.erase(y); 
            }    
        }
        archi_=genera_archi(nodi_);
        return *this;
    }

    grafo operator- (const grafo& g2) {
        grafo g1=*this;
        return g1-=g2;
    }
};