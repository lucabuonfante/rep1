#include <vector>
#include "timecounter.h"
#include "qmsort.h"
#include"randfiller.h"
#include <cmath>
#include "iostream"
#include <algorithm>
#include "sort_mix.h"
std::vector<int> vett_cas () {
    randfiller rf;
    std::vector<int> n(1); //n è la lunghezza del vettore vec
    rf.fill(n,10,10000); //assegniamo alll'unico elemento di vec un numero random
    std::vector<int> vec(n[0]);
    rf.fill(vec, -500,500);
    return vec;
}


int main() {
    int ind=0;
    while (ind<100) {
        std::vector vec = vett_cas(); //uso il randfiller per costruire un vettore di dimensione 20
        sort_mix(vec); //ordino il vettore
        if (is_sorted(vec)==false) {
        return EXIT_FAILURE;
        }
        else {
            ind=ind+1;
        }
    }
    return EXIT_SUCCESS;
}