#include <iostream>
#include "es3_rational.hpp"

using namespace std;

int main() {
    int a;
    int b;
    int c;
    int d;
    cout << "inserire num e den separati da uno spazio r1: \n";
    if (!(cin >> a)) {
        cout << "errore: numero non intero \n"; //legge il primo carattere. se è intero passa avanti
        return 0;
    }
    else if (!(cin >> b)) {
        cout << "errore: numero non intero \n";
        return 0;
    }
    else {
        rational <int> r1(a,b);

        cout << "inserire num e den separati da uno spazio r2: \n";
        
        if (!(cin >> c)) {
        cout << "errore: numero non intero \n";
        return 0;
        }

        else if (!(cin >> d)) {
        cout << "errore: numero non intero \n";
        return 0;
        }

        else {
            rational<int> r2(c,d);
            rational<int> somma = r1+r2;
            rational<int> differenza = r1-r2;
            rational<int> prodotto = r1*r2;
            rational<int> divisione = r1/r2;

            cout <<"r1: "<< r1 <<" \n r2: "<< r2 <<"\n";
            cout <<"Somma: "<< somma << "\n";
            cout <<"Differenza: "<< differenza << "\n";
            cout <<"Prodotto: "<< prodotto << "\n";
            cout <<"divisione: "<< divisione << "\n";

        }


    }
}

