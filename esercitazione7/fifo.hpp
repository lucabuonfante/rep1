#pragma once
#include<queue>


template <typename T>
class fifo {
    private:
    std::queue<T> q;
    public:
    
    void put(const T & e) {
        q.push(e);
    }

    T get() {
        T f= q.front();
        q.pop();
        return f;
    }

    bool empty() {
        return q.empty();
    }

    void rem(){
        q.pop();
    }
};

