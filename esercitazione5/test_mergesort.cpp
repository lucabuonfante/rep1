#include"qmsort.h"
#include"randfiller.h"
#include "ordinamento.h"
#include<vector>

//genera un vettore di numeri casuali
std::vector<int> vett_cas () {
    randfiller rf;
    std::vector<int> n(1); //n è la lunghezza del vettore vec
    rf.fill(n,900,999); //assegniamo all'unico elemento di vec un numero random
    std::vector<int> vec(n[0]);
    rf.fill(vec, -50,50);
    return vec;
}

int main() {
    int ind=0;
    while (ind<100) {
        std::vector vec = vett_cas(); //uso il randfiller per costruire un vettore di dimensione 20
        int l=size(vec);
        mergesort(vec,0,l-1); //ordino il vettore
        if (is_sorted(vec)==false) {
        return EXIT_FAILURE;
        }
        else {
            ind=ind+1;
        }
    }
    return EXIT_SUCCESS;
}