#pragma once
#include "lifo.hpp"
#include "fifo.hpp"
#include "grafo.hpp"
#include<map>
#include<set>
#include<unordered_set>
#include "dir_edges.hpp"

template <typename T, typename cont>
grafo<T> visit_again(const grafo<T> & g, const T& rad, cont & c) { /*c deve essere inizializzato come
    contenitore di edge*/
    
    std::list<dir_edge<T>> visit;
    std::unordered_set<T> visitati;
    /*costruisco la mappa dei nodi visitati e li segno come non visitati*/
    visitati.insert(rad);
    for (const T& v : g.vicini(rad)){
        c.put(dir_edge(rad,v)); /*metto l'arco nel contenitore*/
    }

    while(c.empty()==false){
        dir_edge<T> a=c.get(); /*estraggo l'arco*/
        if (visitati.contains(a.to())==false){ /*se non ho visitato il nodo di destinazione: */
            visitati.insert(a.to()); /*lo segno come visitato*/
            visit.push_back(a); /*lo metto nella lista visit*/
            const std::set<T>& vicini=g.vicini(a.to()); /*considero i suoi vicini*/
        
            for (const T& vicino : vicini){ /*se non ci sono vicini
                non aggiungo nulla allo stack e la radice del ciclo
                viene buttata via da get*/
                c.put(dir_edge(a.to(),vicino));
            }
        
            
        }
            
        
    }
    /*costruisco il grafo prendendo la lista di dir_edge e trasformandola in
    un vettore di unidir_edge, poi uso il costruttore del grafo*/
    int l=visit.size();
    std::vector<unidir_edge<T>> v(l);
    
    auto it=visit.begin(); /*iteratore all'inizio*/
    for (int ind=0; ind<l; ind++) {
        dir_edge<T> a= *it;
        v[ind]=unidir_edge(a.from(),a.to());
        it=std::next(it);
    }

    std::map<T,std::set<T>> mappa_nodi;
    for (const auto& [chiave, set] : g.nodi()){
        mappa_nodi[chiave]={}; /*set vuoto, serve per il costr del
        il grafo*/
    }
    /*così anche i nodi isolati sono inseriti nell'albero di visita*/
    grafo<T> albero(mappa_nodi,v);
    return albero;
}