#include "grafo_pesato.hpp"
#include "edges.hpp"
#include "coppie.hpp"
#include <map>
#include <list>
#include <queue>
#include<unordered_set>


template <typename T>
std::map<T,std::list<T>> dijkstra (T start, grafop<T>& g) { /*per ogni noddo mettiamo il vettore di precedenti in ordine*/
    
    std::priority_queue<coppia<T>> pq; /*inizializza la priority queue*/
    pq.push(coppia<T>(start,0));
    
    std::map<T,std::list<T>> percorso;
    percorso[start].push_back(start); /*in questo modo i percorsi sono tutti nella forma 
    {start, nodo1,...}*/
    
    std::map<T,int> visitati; /*set di nodi  visitati con le distanze*/
    visitati[start]=0;
    
    

    while (pq.empty()==false) { 
        coppia<T> c = pq.top(); /*prendo il primo nodo dei pq, ossia il più vicino a s*/
        T rad= c.nodo();
        pq.pop();
        for(const T& vicino : g.vicini(rad)){ /*per ogni suo vicino*/
            if (visitati.contains(vicino)==true){ /*se ho già visitato il vicino*/
                if (visitati.at(vicino)> visitati.at(rad)+g.peso(rad,vicino)) { /*se è più facile arrivarci 
                    passando dal nodo rad*/
                    
                    int nuovadist= visitati.at(rad)+g.peso(rad,vicino);
                    
                    visitati.at(vicino)=nuovadist;
                    
                    pq.push(coppia<T>(vicino,nuovadist));
                    
                    percorso[vicino]=percorso[rad];
                    percorso[vicino].push_back(vicino); /*è più veloce arrivare al vicino passando da rad
                    piuttosto che direttamente*/
                }
                else{}/*non modifichiamo il percorso per arrivare a "vicino". 
                non aggiungiamo "vicino" alla coda perché il percorso per arrivarci da rad 
                è già ottimale  */
            }    
            else { /*se non ho ancora un modo per arrivare al vicino, ci arrivo passando da rad. aggiungo
                    questa distanza alla mappa visitati*/
                    
                    int nuovadist=visitati[rad]+g.peso(rad,vicino);
                    
                    visitati[vicino]=nuovadist;
                    
                    pq.push(coppia<T>(vicino, nuovadist));
                    
                    percorso[vicino]=percorso[rad];
                    percorso[vicino].push_back(vicino); 
                    /*per arrivare al vicino passiamo ovviamente da rad*/
            }
        }
    }
    return percorso;
} 