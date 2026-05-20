#pragma once //compila 1 sola volta
#include <iostream>
#include <cmath> 
#include <vector>

template<typename T>
class dir_edge {
    private:
    T from_;
    T to_;

    public:
    
    dir_edge() {}
    
    dir_edge(const T& f, const T& t){
        from_=f;
        to_=t;
    }

    const T& from() const {
        return from_;
    }

    const T& to() const {
        return to_;
    }

};


template<typename T>
std::ostream&
operator << (std::ostream& os, const dir_edge<T>& edge) {
    os << "from: " << edge.from() << " to: " << edge.to() << "\n";
    return os;
}