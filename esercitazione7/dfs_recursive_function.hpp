#pragma once
#include <iostream>
#include "grafo.hpp"
#include<stack>
#include "lifo.hpp"
#include <map>
#include <unordered_set>

template <typename T>
void dfs_recursive_function(T rad, grafo<T>& g, std::map<T,std::set<T>>& visit, std::unordered_set<T>& visitati) {
    
    visitati.insert(rad);
    for (auto& vicino : g.vicini(rad)) {
        if (visitati.contains(vicino)==false) {
            visit[rad].insert(vicino);
            visit[vicino].insert(rad);
            dfs_recursive_function(vicino, g, visit, visitati);
        }
    }
     

}