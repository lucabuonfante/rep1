#include<iostream>
using namespace std;

int main()
{
    double ad[4] = {0.0, 1.1, 2.2, 3.3}; //array di double
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7}; //array di float
    int ai[3] = {0, 1, 2}; //array di int

    int x = 0;
    
    float y = 1.1;
    
    (&y)[1] = 0; // siccome &y è un puntatore a float, prende la posizione di y, si sposta di 1*sizeof(float) = 4 e lì ci mette il float 0
    
    //che cosa c'è se mi sposto in avanti di un blocco da dove ho salvato y?
    // siccome y è un float, mi devo spostare in avanti di 4 byte. 
    //float* pdy= &//punta all'elemento dopo y

    cout << x << "\n";

    //return 0;
}
