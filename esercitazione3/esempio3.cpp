#include<iostream>
#include<cassert>
#include<vector>
using namespace std;

template<typename T>
class vec2 {
    T x_;
    T y_;
public:
    vec2() //costruttore di default
    :x_(T{0.0}), y_(T{0.0}) //inizializza i vettori a 0 convertito in tipo T
    {}

    
    vec2(const T& px, const T& py) //costr user defined. rimane costante l'oggetto px, che si trova all'indirizzo T&
    :x_(px), y_(py)
    {}
    //il metodo (funzione) precedente svolge lo stesso compito del seguente, ma 
    //nel primo si assegna il posto in memoria e il valore alla variabile in un solo colpo
    //nel secondo prima si assegna il posto in memoria e poi il valore alla variabile.
    //questo secondo metodo può dare dei problemi se x_ è definita come const
    //vec2(const T& px, const T& py) {
      // x_=px;
      // y_=py;

    //}
    
    

    //restituiscono i valori di x e y
    T x() const{
        return x_;
    } //metodo (funzione) che restituisce un elemento di tipo T, in particolare x_
    
    T y() const{
        return y_;
    }
    
    
    //OVERLOAD PER LA SOMMA
    vec2& operator +=(const vec2& other)  { // "operator+= " è il nome speciale che dice al 
        //C++ di usare questa funzione ogni volta che viene usato il simbolo += con oggetti vec2
        // "other" è il riferimento a vec2
       x_ += other.x_; //x_= se stesso + la x_ dell'elemento (di tipo vec) salvato in vec2&
       y_ += other.y_;
       return *this; //restituisce l'elemento presente all'indirizzo indicato
       //da "this", ossia il primo vettore che sommo, che è stato modificato dalla somma

    }
    //con questq funzione il risultato della somma sostituisce il primo addendo.
    //con la prossima, la somma viene salvata separatamente. 
    //mettiamo const dopo le (...) perché garantiamo che gli addendi non verranno modificati

    vec2 operator+ (const vec2& other) const{ 
        vec2 ret= *this; //COPIA del primo vettore
        ret+=other; //ret=ret + other. sostituiamo ret (usando la funzione definita prima), che non è il vettore originale, ma una sua copia
        return ret; // restituisce il risultato, salvato al posto della copia del primo vettore
    }

    //implementazione del prodotto vettore-scalare

    vec2& operator*=(const T& scalare) {
        (*this).x_= (*this).x_ * scalare;
        (*this).y_ = (*this).y_ * scalare;
        
        return *this;
    }

    vec2 operator*(const T& scalare) const {
        vec2 ret=*this; //copia del primo vettore;
        ret=ret*=scalare;
        return ret;

    }

    
  

};



int main() {
    vec2<double> a(1.0,2.0);
    vec2<double> b(2.0,3.0);
    vec2<double> c=a+b;
    cout << c.x() << " , " << c.y() << "\n";
    return 0; //accessorio
}