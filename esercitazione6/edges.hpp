#pragma once //ccompila 1 sola volta
#include <iostream>
#include <cmath> 
#include <vector>

template<typename T>
class unidir_edge {
    private:
    T from_;
    T to_;

    public:
    /*costruttore di default (AI)*/
    unidir_edge() {}
    
    /*fa in modo che il from sia < di to*/
    unidir_edge(const T& from, const T& to) {
        if (from < to) {
        from_=from;
        to_=to;
        }
        else {
            from_=to;
            to_=from;
        }
    }

    const T& from() const {
        return from_;
    }

    const T& to() const {
        return to_;
    }

    /* e1 è < di e2? */
    bool operator < (const unidir_edge e2) const {
        /* prima confronto i nodi from_ poi, se sono uguli, i nodi to()*/
        if (from_ < e2.from()) {
            return true;
        }  
        else if (from_== e2.from() && to_ < e2.to()) {
            return true;
        }

        else {
            return false;
        }
    }

    bool operator == (const  unidir_edge& e2) const {
        if (from_==e2.from() && to_ == e2.to()) {
            return true;
        }
        else {
            return false;
        }
    }

    

};


template<typename T>
std::ostream&
operator << (std::ostream& os, const unidir_edge<T>& edge) {
    os << "from: " << edge.from() << " to: " << edge.to() << "\n";
    return os;
}