#pragma once
#include<stack>

template <typename T>
class lifo {
    private:
    std::stack<T> s;

    public:
    
    void put(const T&e) {
        s.push(e);
    }

    T get() {
        T t=s.top();
        s.pop();
        return t;
    }

    bool empty() {
        return s.empty();
    }

    void rem(){
        s.pop();
    }
};


