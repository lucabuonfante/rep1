#include<iostream>
#include<cassert>
#include<vector>
using namespace std;

template<typename I>
requires integral <I>
class rational {
    I num_;
    I den_;
    public:
    
    I mcd(I n,I d) {
        I a;
        I b;
        if (abs(n)>abs(d)) {
            a=abs(n);
            b=abs(d);
        }
        else {
            a=abs(d);
            b=abs(n);
        }
        I r=b;
        while (b!=0) {
            r=b;
            b=a%b;
            a=r;
        }
        return r;

    }
    
    rational& semplifica() {
        if (den_!=0 && num_!=0) { 
            I m=mcd(num_ , den_);
            num_=num_/m;
            den_=den_/m;
            return *this;
        }
        else {
            return *this;

        }
    }
    
    rational() //costruttore di default
    :num_(0), den_(1)
    {}

    rational(const I& n, const I& d) { //costruttore definito dall'utente    
        num_=n;
        den_=d;
        semplifica();
    }

    I numeratore() const {
        return num_;
    }

    I denominatore() const {
        return den_;
    }
    
    
    rational& operator += (const rational& ad2) {
        //casi NaN:
        if (den_==0 && num_==0) { //nan + num = nan
            num_=0;
            den_=0;
            return *this;
        }
        else if (ad2.den_==0 && ad2.num_==0){ //num + nan = nan
            num_=0;
            den_=0;
            return *this;
        }
        //casi infinito:
        else if (den_==0 || ad2.den_==0) { //se siamo arrivati qui vuol dire che nessuno dei due addendi è nan
            num_=1;
            den_=0;
            return *this;
        }
        //caso regolare:
        else {
            num_=num_*ad2.den_ + ad2.num_*den_;
            den_= den_ * ad2.den_;
            semplifica();
            return *this;
        }
    }
        
    
    
    rational operator + (const rational ad2) const {
        rational ret = *this; //elemento indicato da this, ossia il primo addendo
        ret += ad2; //qui sono già gestiti i casi patologici
        return ret; 
    }

    void stampa () const {
        if (den_!=0) {
            if (num_==0) { // 0/num = 0
                cout << 0 << "\n";
            }
            else { // num/num
                cout << " (" << num_ << " / " << den_ << ") \n";
            }
        }
        //casi in cui il denominatore è =0
        else if (num_==0) { //  0/0
            cout << "NaN \n";
        }
        else {
            if (num_<0) { 
                cout << "- infinito \n";
            }
            else {
                cout << "+ infinito \n";
            }
        }
    }
    
        
    
    
    rational& operator *= (const rational& fat2) {
        //casi NaN:
        if (den_==0 && num_==0) { //nan * numero = nan
            num_=0;
            den_=0;
            return *this;
        }
        else if (fat2.den_==0 && fat2.num_==0){ //numero * nan = nan
            num_=0;
            den_=0;
            return *this;
        }
        else if (den_==0 && fat2.num_==0) { // infinito * 0 = nan
            num_=0;
            den_=0;
            return *this;
        }
        
        else if (num_==0 && fat2.den_==0) { //  0 * infinito = nan
            num_=0;
            den_=0;
            return *this;
        }

        //caso infinito
        else if (den_==0 || fat2.den_==0) { 
            num_=(num_*fat2.num_)/abs(num_*fat2.num_); //viene +1 o -1 a seconda del segno del numeratore del prodotto 
            //(!=0 perché sennò uno dei due sarebbe nan se saremmo ricaduti in uno dei casi precedenti)
            den_=0;
            return *this;
        }
        //caso regolare:
        else {
            num_=num_ * fat2.num_;
            den_=den_* fat2.den_;
            semplifica(); //l'argomento della funzione è il razionale che stiamo trattando
            //se invvece fosse fuori dalla classe dovremmo scrivere a.semplifica(). 
            return *this;
        }    
    }

    rational operator * (const rational fat2) const {
        rational ret= *this;
        ret*=fat2; //invochiamo *=, quindi sostituiamo ret ocn il risultato dell'operazione
        return ret;
    }

    rational& operator -= (const rational sot) {
        //casi NaN:
        if (den_==0 && num_==0) { //nan - num = nan
            num_=0;
            den_=0;
            return *this;
        }
        else if (sot.den_==0 && sot.num_==0){ //num - nan = nan
            num_=0;
            den_=0;
            return *this;
        }
       
        else if (den_==0 && sot.den_==0) { //se siamo arrivati qui vuol dire che nessuno dei due addendi è nan, ma inf - inf = nan
            num_=0; 
            den_=0;
            return *this;
        }

        else if (den_==0) { //inf - num = inf
            num_=1;
            den_=0;
            return *this;
        }

        else if (sot.den_==0) { //num - inf = -inf
            num_=-1;
            den_=0;
            return *this;
        }
        
        
        //caso regolare:
        else {
            num_=num_*sot.den_ - sot.num_*den_;
            den_= den_ * sot.den_;
            semplifica();
            return *this;
        }
    }
        
    rational operator - (const rational sot) const {
        rational ret= *this;
        ret -= sot;
        return ret;
    }

    rational& operator /= (const rational& ds) {
        // caso NaN/numero e caso numero / NaN
        if ((den_==0 && num_==0) || (ds.den_==0 && ds.num_==0) ) {
            num_=0;
            den_=0;
            return *this;
        }
        
        //caso infinito (lascio la possibilità di dividere per infinito. in questo caso il risultato è direttamente 0)
        
        else if ((num_==0 && ds.num_==0) || (den_==0 && ds.den_==0)) {     //caso inf/inf e 0/0. i due numeri non possono essere nan perché
            //saremmo ricaduti nel caso precedente
            num_=0;
            den_=0;
            return *this;
        }
        else if (den_==0 || ds.num_==0) { //se il dividendo è = +-infinito o il divisore è =0 la divisione dà +-infinito
            num_=num_/abs(num_);
            den_=0;
            return *this;
        }
        else {
            den_=den_*ds.num_;
            num_=num_*ds.den_;
            semplifica();
            return *this;
        }
    }

    rational operator / (const rational ds) const {
        rational ret=*this; //ret è una copia di ciò che sta in "this" ma che non sta in "this", 
        ret/=ds;
        return ret;
    }

};

int main() {
    rational<int> a(3,4);
    rational<int> b(5,6);
    rational<int> somma=a+b;
    rational<int> differenza= a-b;
    rational<int> prodotto = a*b;
    rational<int> divisione = a/b;
    rational<int> n(0,0);
    rational<int> inf(1,0);
    rational<int> inf_neg(-1,0);
    rational<int> diff_inf_neg = a-inf;
    rational<int> div_inf_neg= inf_neg/a;
    rational<int> diff_nan=a-n;
    rational<int> molt_nan =a*n;
    somma.stampa();
    differenza.stampa();
    prodotto.stampa();
    divisione.stampa();
    diff_inf_neg.stampa();
    div_inf_neg.stampa();
    diff_nan.stampa();
    molt_nan.stampa();
    return 0;
}


