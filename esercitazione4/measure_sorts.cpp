#include <vector>
#include "timecounter.h"
#include"randfiller.h"
#include "ordinamento.h"
#include <cmath>
#include "iostream"
#include <algorithm>
int main() {
    timecounter tc;
    randfiller rf;
    int n=2;
    std::vector<double> t_bubble(12); //il vettore è lungo 12 perché ospita i numeri da 2 a 13
    std::vector<double> t_ins(12);
    std::vector<double> t_sel(12);
    std::vector<double> t_sort(12);
    while (n<=13) {
        int i= pow(2,n);
        std::vector<int> vec(i); //inizializzo un vettore della dimensione 2^n
        rf.fill(vec,-50,50); //lo riempiamo di numeri casuali
        
        //tempo bubblesort
        tc.tic();
        bubblesort(vec); 
        double secs=tc.toc();
        t_bubble[n-2]=secs;

        tc.tic();
        ins_sort(vec); 
        secs=tc.toc();
        t_ins[n-2]=secs;

        tc.tic();
        sel_sort(vec); 
        secs=tc.toc();
        t_sel[n-2]=secs;

        
        std::vector<int> v=vec; //le funzioni che ho definito io lavorano su copie, questa 
        //potrebbe lavorare sul vettore originale, quindi creo una copia per sicurezza
        tc.tic();
        std::sort(v.begin(), v.end()); 
        secs=tc.toc();
        t_sort[n-2]=secs;
        
        std::cout << "dim: " << i << " t_B: " << t_bubble[n-2] << " t_I: " << t_ins[n-2] << " t_S: " << t_sel[n-2] << " t_sort: " << t_sort[n-2] << "\n" << "\n";


        n=n+1;
    }
    
}