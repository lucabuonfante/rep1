
#include <iostream>
#include <vector>


template <typename T>
std::vector<T> ins_sort(std::vector<T> &vec) {
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