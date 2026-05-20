#pragma once
#include <iostream>
#include "grafo.hpp"
#include<stack>
#include "lifo.hpp"
#include "dfs_recursive_function.hpp"
#include <map>
#include <unordered_set>

template <typename T>
grafo<T> dfs_rec_final(const T& rad, const grafo<T>& g){
    
    std::map<T,std::set<T>> visit;    
    dfs_recursive_function(rad, g,visit);
    
    /*gestione dei nodi isolati: se un nodo non è stato 
    trovato da visit, vuol dire che è isolato. Lo inserisco
    comunque nell'albero di visita. considero vuoto il set dei suoi vicini.
    Se la chiave inserita all'inizio è un nodo isolato, verrà inserito solo 
    lui in visit, quindi tutti gli altri nodi verranno trattati come isolati: */
    for (const auto& nodo_is : g.all_nodes()){
        if (visit.contains(nodo_is)==false){
            visit[nodo_is]={};
        }
    }
    grafo<T> albero(visit); 
    return albero;
}