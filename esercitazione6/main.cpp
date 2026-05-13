#include "edges.hpp"
#include "set_nodes.hpp"
#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <map>

void stampa_grafo(const grafo<int>& g)  {
    
    std::cout << "nodi: ";
    for (const auto& nodo : g.all_nodes()) {
        std::cout << nodo << " ";
    }
    std::cout << "\n numero archi: " << g.archi().size() << "\n";
    for (const auto& arco : g.all_edges()) {
        std::cout << "numero: " << g.edge_number(arco) << " arco: " << arco << "\n";
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

    
    grafo<int> g2;

    
    
    g2.add_edge(unidir_edge<int>(0, 2)); // Arco in comune
    g2.add_edge(unidir_edge<int>(3, 6)); // Arco inesistente in g1

    
    std::cout<<" g1: \n";
    stampa_grafo(g1);
    
    std::cout<< " g2: \n";
    stampa_grafo(g2);

    grafo g6=grafo(g2);
    std::cout << "copia del grafo g2: \n";
    stampa_grafo(g6);

    
    std::cout << " g1 - g2 = \n";
    grafo<int> g3 = g1-g2;
    
    
    stampa_grafo(g3);
    
    /*test costruttore 1*/
    std::cout<< " test costruttore 1: \n";
    /*mappa con i nodi ma con set vuoti*/
    std::map<int, std::set<int>> mv;
    for (int i=1; i<=4; i++){
        mv[i] = std::set<int>();
    }

    /*archi*/
    std::vector<unidir_edge<int>> a(4);
    a[0]=unidir_edge<int>(1, 2);
    a[1]=unidir_edge<int>(2, 3);
    a[2]=unidir_edge<int>(3, 4);
    a[3]=unidir_edge<int>(4, 1); 

    
    grafo<int> g4(mv, a);
    
    
    stampa_grafo(g4);
    std::cout << "\n";


   
    std::cout << "test costruttore 2: \n";
    
    
    std::map<int, std::set<int>> mp;
    
    mp[10] = {20, 30};      
    mp[20] = {10, 40};      
    mp[30] = {10};          
    mp[40] = {20};         

    
    grafo<int> g5(mp);
    
    
    stampa_grafo(g5);
    std::cout << "\n";

    


return 0;    
}






