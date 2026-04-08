

#include <iostream>
#include <vector>

template <typename T>
bool is_sorted(const std::vector<T>& vec) {
    int l = vec.size();
    if (l==0) {
        return true;
    }
    else {
        int ind=0;
        while (ind<l-1) {
            if (vec[ind]<= vec[ind+1]) {
                ind=ind + 1;
            }
            else {
                return false; //la funzione termina qui
            }
        }
        return true;
    }     
}

template <typename T>
std::vector<T> bubblesort(std::vector<T> vec) {
    int l=vec.size();
    int ind1=0;
    while (ind1<l-1) { //scorro dall'inizio alla fine 
        int ind2=l-1;
        while (ind2>ind1) { //scorro dalla fine all'indice
            T a=vec[ind2];
            T b=vec[ind2-1];
            if (a<b) {
                vec[ind2]=b;
                vec[ind2-1]=a;
            }
            else {}
            ind2=ind2-1;

        }
        ind1=ind1+1;
    }
    return vec;
}


template <typename T>
std::vector<T> ins_sort(std::vector<T> vec) {
    int j=1;
    int l=size(vec);
    while (j<l) {
        T key=vec[j];
        int i = j-1;
        while (i>=0 &&  vec[i] > key) {
            vec[i+1] = vec[i];
            i=i-1;
        }
        vec[i+1]=key;
        j=j+1;
    }
    return vec;
}

//selection sort

template <typename T>
std::vector<T> sel_sort(std::vector<T> vec) {
    int i=0;
    int l=size(vec);
    int min=0;
    while (i < l-1) {
        min=i;
        int j=i+1;
        while (j<l) {
            if (vec[j] < vec[min]) {
                min=j;
            }
            else {}
            j=j+1;
        }
        T r=vec[i];
        vec[i]=vec[min];
        vec[min]=r; 
        i=i+1;
    }
    return vec;
}


