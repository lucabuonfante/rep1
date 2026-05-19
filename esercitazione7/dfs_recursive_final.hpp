#pragma once
#include <iostream>
#include "grafo.hpp"
#include<stack>
#include "lifo.hpp"
#include "dfs_recursive_function.hpp"
#include <map>
#include <unordered_set>

template <typename T>
grafo<T> final(T rad, grafo<T> g){
    
    std::map<T,std::set<T>> visit;
    std::unordered_set<T> visitati;    
    dfs_recursive_function(rad, g,visit,visitati); 
    grafo<T> albero(visit); 
    return albero;
}