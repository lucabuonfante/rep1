#pragma once
#include <set>
#include <map>
#include <list>
#include "edges.hpp"
#include<queue>
#include<algorithm>
#include<list>
#include "coppie.hpp"
#include<map>

template <typename T>
class grafop {

    private:
    std::map<T, std::set<T>> nodi_;
    std::map<unidir_edge<T>,int> archi_;

    public:
    grafop() {
        nodi_= std::map<T, std::set<T>>();
        archi_ = std::map<unidir_edge<T>,int>(); 
    }

    grafop(const std::map<T, std::set<T>> nodi, const std::map<unidir_edge<T>,int> archi) {
        nodi_=nodi;
        archi_=archi;
    }

    std::map<T, std::set<T>>& nodi() const {
        return nodi_;
    }

    std::map<unidir_edge<T>,int> archi() const {
        return archi_;
    }

    /*prende una chiave e restituisce il set*/
    const std::set<T>& vicini ( const T& chiave) const {
        return nodi_.at(chiave); /*usiamo at così se la chiave non c'è
        restituisce un'eccezione*/
    }

    int peso(const T& nodo1, const T& nodo2) const {
    /*prendo come peso l'elemento associato all'arco 
    nella mappa, che ha come chiavi gli archi. devo fare l'if perché gli 
    archi hannno i nodi ordinati*/
    
        int p= archi_.at(unidir_edge<T>(nodo1,nodo2)); /*uso .at() perché
        dichiaro il metodo come const, mentre l'operatore [] potrebbe modificare archi_*/  
        return p;
    }



};

