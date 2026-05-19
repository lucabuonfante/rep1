#pragma once


template <typename T>
class coppia {
    private:
    T nodo_;
    int dist_;

    public:

    /*costruttori di default*/
    coppia() {
        
        dist_=0;
    }

    coppia (const T& nodo, int dist) {
        nodo_=nodo;
        dist_=dist;
    }

    const T& nodo() const {
        return nodo_;
    }

    int dist() const {
        return dist_;
    }

    bool operator < (const coppia& c2) const {
        
        if (dist_ > c2.dist()) { /*inverto le relazioni di > e < cosi
            nella priority queue ci sarà prima il nodo più vicino*/
            return true;
        }  
        else {
            return false;
        }
    }

    bool operator == (const  coppia& c2) const {
        if (dist_==c2.dist()) {
            return true;
        }
        else {
            return false;
        }
    }


};
