#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int main() {

    static const int N=4;
    double arr[N]={1.1 , 2.2, 9.9, 3.3};
    double minimo=arr[0];
    double massimo=arr[0];
    double somma=arr[0];
    int ind=1;
    while (ind<N) {//ind parte dal secondo elemento arriva a N-1, che indica l'ultimo elemento dell'array
        double elemento=arr[ind];
        minimo=min(elemento,minimo);
        massimo=max(elemento, massimo);
        somma=somma+elemento;

        ind=ind+1;
    }

    double media= somma/N;
    ind=0;
    float distq=0;
    while (ind<N) {
        double elemento=arr[ind];
        distq=distq + pow(abs(elemento - media),2);
        ind=ind+1;

    }
    double devstd= sqrt((distq)/N);

    cout << "minimo: " << minimo << "\n" << "massimo: " << massimo << "\n" << "dev std: " << devstd << "\n";

    //algoritmo di ordinamento bubblesort
    ind=0;
    while (ind<N-1) { //il ciclo arriva all'elemento di posto N-2, ossia il N-1 esimo 
        double p=arr[ind];
        double s=arr[ind+1];
        if (p>s) {
            arr[ind]=s;
            arr[ind+1]=p;
        }
        ind=ind+1;
    }
    
    ind=0;
    while (ind<N) {
        cout << arr[ind] << "\n";
        ind=ind+1;
    }
}
