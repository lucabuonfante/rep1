#pragma once
#include "lifo.hpp"
#include "fifo.hpp"
#include "grafo.hpp"
#include<map>
#include<set>
#include<unordered_set>

template <typename T, typename cont>
grafo<T> graph_visit(const grafo<T> & g, const T& rad, cont & c) {
    /*prendo un nodo, controllo i vicini e tolgo quelli che non visito
    poi ricostruisco gli archi con genera_archi*/
    std::map<T,std::set<T>> visit;
    std::unordered_set<T> visitati;
    /*costruisco la mappa dei nodi visitati e li segno come non visitati*/
    
    c.put(rad); /*metto la radice nel contenitore*/
    
    while(c.empty()==false) {
        T e=c.get();
        std::set<T> vicini=g.vicini(e);
        for (auto& vicino :vicini) {
            if (visitati.contains(vicino)==false) {
                visitati.insert(vicino);
                c.put(vicino);
                visit[e].insert(vicino);
                visit[vicino].insert(e);
            }
        }
        
    }
    grafo<T> albero(visit);
    return albero;
    
}