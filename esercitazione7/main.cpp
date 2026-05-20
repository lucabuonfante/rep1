#include "edges.hpp"
#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include "visit.hpp"
#include <stack>
#include <queue>
#include "fifo.hpp"
#include "lifo.hpp"
#include "dijkstra.hpp"
#include "grafo_pesato.hpp"
#include "dfs_recursive_final.hpp"
#include "visit_again.hpp"

void stampa_grafo(const grafo<int>& g)  {
    
    std::cout << "nodi: ";
    for (const auto& nodo : g.all_nodes()) {
        std::cout << nodo << " ";
    }
    std::cout << "\n numero archi: " << g.archi().size() << "\n";
    for (const auto& arco : g.all_edges()) {
        std::cout  << " " << arco.from() << " -- " << arco.to()<< "\n";
    }
    std::cout << "\n";
    
}


int main() {
    
    

    grafo<int> g1; /*inizializzo un grafo<int> vuoto*/
    
    g1.add_edge(unidir_edge<int>(0, 1)); /*sfrutto il fatto che add edge aggiunge anche i nodi se questi
    non sono già nel grafo*/
    g1.add_edge(unidir_edge<int>(0, 2)); /*arco che deve essere rimosso*/
    g1.add_edge(unidir_edge<int>(1, 2));
    g1.add_edge(unidir_edge<int>(2, 3));
    g1.add_edge(unidir_edge<int>(3, 4));
    g1.add_edge(unidir_edge<int>(4, 5));
    g1.add_edge(unidir_edge<int>(1, 4));
    g1.add_edge(unidir_edge<int>(2, 5));
    std::cout << "grafo g1: \n";
    stampa_grafo(g1);
    
    std::cout << "dfs iterativa (visit_again) \n";
    lifo<dir_edge<int>> s;
    grafo<int> albero= visit_again(g1,0,s);
    stampa_grafo(albero);

    /*dfs ricorsiva*/
    std::cout << "dfs ricorsiva \n";
    int rad=0;
    grafo<int> albero3= dfs_rec_final(rad, g1);
    stampa_grafo(albero3);

    std::cout << "visit_again, bfs";
    fifo<dir_edge<int>> c;
    grafo<int> albero2= visit_again(g1,0,c);
    stampa_grafo(albero2);

    std::cout << "grafo sbagliato dfs (visit): ";
    lifo<int> s1;
    grafo<int> albero4= graph_visit(g1,0,s1);
    stampa_grafo(albero4);


    /*costruzione del grafo pesato per dijkstra*/
    std::map<int, std::set<int>> v2=g1.nodi();
    std::map<unidir_edge<int>,int> a2;

    a2[unidir_edge<int>(0, 1)]=2;
    a2[unidir_edge<int>(0, 2)]=3; 
    a2[unidir_edge<int>(1, 2)]=6;
    a2[unidir_edge<int>(2, 3)]=5;
    a2[unidir_edge<int>(3, 4)]=10;
    a2[unidir_edge<int>(4, 5)]=1;
    a2[unidir_edge<int>(1, 4)]=3;
    a2[unidir_edge<int>(2, 5)]=7;
    grafop gpes(v2,a2);
    std::map<int,std::list<int>> ml= dijkstra(0,gpes);

    for (auto& [elemento, lista] :ml) {
        std::cout<< "arrivo: " << elemento << "\n";
        for (int& el : lista) {
            std::cout << el << "\n";
        }
    }



return 0;    
}






