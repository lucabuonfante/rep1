#include <vector>
#include "timecounter.h"
#include "qmsort.h"
#include"randfiller.h"
#include "ordinamento.h"
#include <cmath>
#include "iostream"
#include <algorithm>
int main() {
randfiller rf;
int n=100;
std::vector<int> vec(100); //inizializzo un vettore di dimensione n
rf.fill(vec,-50,50); //lo riempiamo di numeri casuali
for (int ind=0; ind<=n; ind++) {
    std::cout<< vec[ind] << "\n";
}
std::vector<int> A=quicksort(vec,0,n-1);

std::cout << "vettore ordinato: ";
for (int ind=0; ind<=n; ind++) {
    std::cout<< A[ind] << "\n";
}
 return 0;
}