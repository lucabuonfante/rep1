#pragma once
#include <iostream>
#include "grafo.hpp"
#include<stack>
#include "lifo.hpp"
#include <map>
#include <unordered_set>

template <typename T>
void dfs_recursive_function(const T& rad, const grafo<T>& g, std::map<T,std::set<T>>& visit) {
    
    for (const auto& vicino : g.vicini(rad)) {
        if (visit.contains(vicino)==false) {
            visit[rad].insert(vicino);
            visit[vicino].insert(rad);
            dfs_recursive_function(vicino, g, visit);
        }
    }
     

}