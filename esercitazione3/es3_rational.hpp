#pragma once //ccompila 1 sola volta
#include <iostream>
#include <concepts> //fa funzionare il requires
#include <cmath> 

template<typename I>
requires std::integral <I>
class rational {
    private:
    I num_;
    I den_;
    
    I mcd(I n,I d) { // mcd tra i valori assoluti
        I a;
        I b;
        if (std::abs(n)>std::abs(d)) {
            a=std::abs(n);
            b=std::abs(d);
        }
        else {
            a=std::abs(d);
            b=std::abs(n);
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
            if (den_<0) { //sposta il - sul numeratore
                num_ = -num_;
                den_= -den_;
            }
            else {}
            I m=mcd(num_ , den_);
            num_=num_/m;
            den_=den_/m;
            return *this;
        }
        else {
            return *this;

        }
    }
    
    public:
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
            num_=(num_*fat2.num_)/std::abs(num_*fat2.num_); //viene +1 o -1 a seconda del segno del numeratore del prodotto 
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
            num_=num_/std::abs(num_);
            den_=0;
            return *this; //la divisione per 0 dà sempre +infinito, perché non faremo distinzione tra 0/positivo e 0/negativo: è sempre 0
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


template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r) {//overload dell'operatore <<
   
    if (r.denominatore()!=0) { //casi non patologici
        if (r.numeratore()==0) { // 0/num = 0
            os << 0 << "\n";
        }
        else { // num/num
            os << " (" << r.numeratore() << " / " << r.denominatore() << ") \n";
        }
    }
    //casi in cui il denominatore è =0
    else if (r.numeratore()==0) { //  0/0
        os << "NaN \n";
    }
    else { //numero / 0
        if (r.numeratore()<0) { 
            os << "- infinito \n"; //numero neg
        }
        else {
            os << "+ infinito \n"; //numero pos
        }
    }
    return os;
}
