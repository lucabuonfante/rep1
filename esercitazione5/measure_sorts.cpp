#include <vector>
#include "timecounter.h"
#include "qmsort.h"
#include"randfiller.h"
#include "sort_mix.h"
#include "ordinamento.h"
#include <cmath>
#include "iostream"
#include <algorithm>

//test su vettori piccoli
int main() {
    timecounter tc;
    randfiller rf;
    int n=2;
    std::vector<double> t_bubble(99); //il vettore è lungo 99 perché ospita i numeri da 2 a 100
    std::vector<double> t_ins(99);
    std::vector<double> t_sel(99);
    std::vector<double> t_sort(99);
    std::vector<double> t_merge(99);
    std::vector<double> t_quick(99);
    std::vector<double> t_mix(99);

    while (n<=100) { //dimensione dei vettori
        int d=10*n;
        t_bubble[n-2]=0; //mettiamo a 0 la componente del vettore relativa alla dimensione n
        t_ins[n-2]=0;
        t_sel[n-2]=0;
        t_sort[n-2]=0;
        t_merge[n-2]=0;
        t_quick[n-2]=0;
        t_mix[n-2]=0;

        for (int l=0; l<100; l++) { //per ogni dimensione creo 100 vettori e li ordino    
            std::vector<int> vec(d); //inizializzo un vettore di dimensione n
            rf.fill(vec,-5000,5000); //lo riempiamo di numeri casuali
            
            std::vector<int> A1= vec;
            tc.tic();
            bubblesort(A1); 
            double secs=tc.toc();
            t_bubble[n-2]=t_bubble[n-2]+secs;
            
            std::vector<int> A2= vec;
            tc.tic();
            ins_sort(A2); 
            secs=tc.toc();
            t_ins[n-2]=t_ins[n-2]+secs;

            std::vector<int> A3= vec;
            tc.tic();
            sel_sort(A3); 
            secs=tc.toc();
            t_sel[n-2]=t_sel[n-2]+secs;

            
            std::vector<int> v=vec; //le funzioni che ho definito io lavorano su copie, questa 
            //potrebbe lavorare sul vettore originale, quindi creo una copia per sicurezza
            tc.tic();
            std::sort(v.begin(), v.end()); 
            secs=tc.toc();
            t_sort[n-2]=t_sort[n-2]+secs;
            
            std::vector<int> w=vec;
            tc.tic();
            std::vector<int> p(w.size());
            mergesort2(w,0,d-1,p); 
            secs=tc.toc();
            t_merge[n-2]=t_merge[n-2]+secs;
            
            std::vector<int> g=vec;
            tc.tic();
            quicksort(g,0,d-1); 
            secs=tc.toc();
            t_quick[n-2]=t_quick[n-2]+secs;

            std::vector<int> A4=vec;
            tc.tic();
            sort_mix(A4); 
            secs=tc.toc();
            t_mix[n-2]=t_mix[n-2]+secs;
        }
    //ora ogni elemento dei vettori dei tempi è la somma dei tempi necessari e ordinarli
    //tutti e 100 (quelli di lunghezza n)
    t_quick[n-2]=t_quick[n-2]/100;
    t_merge[n-2]=t_merge[n-2]/100;
    t_sort[n-2]=t_sort[n-2]/100;
    t_sel[n-2]=t_sel[n-2]/100;
    t_ins[n-2]=t_ins[n-2]/100;
    t_bubble[n-2]=t_bubble[n-2]/100;
    t_mix[n-2]=t_mix[n-2]/100;
        
    std::cout  << d << "," << t_bubble[n-2] << "," << t_ins[n-2] << "," << t_sel[n-2] << "," << t_sort[n-2] << "," << t_merge[n-2] << ","  << t_quick[n-2] << "," << t_mix[n-2] << "; \n";
    n=n+1;
    }
    
}