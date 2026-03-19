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
}
