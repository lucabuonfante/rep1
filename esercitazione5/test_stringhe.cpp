#include <iostream>

#include <vector>
#include "ordinamento.h"
#include"qmsort.h"
#include "sort_mix.h"

int main() {
    
    std::vector<std::string> vec(10);
    vec[0]="a";
    vec[1]="b";
    vec[2]="h";
    vec[3]="au";
    vec[4]="y";
    vec[5]="a5";
    vec[6]="ik";
    vec[7]="ah";
    vec[8]="y";
    vec[9]="w";
    std::vector<std::string> v=bubblesort(vec);
    std::vector<std::string> w=vec;
    ins_sort(w);
    std::vector<std::string> z=sel_sort(vec);
    std::vector<std::string> k=vec;
    mergesort(k,0,9);
    std::vector<std::string> x=vec;
    quicksort(x,0,9);
    std::vector<std::string> r=vec;
    sort_mix(r);
    
    
    if (is_sorted(v)==true && is_sorted(w)==true &&  is_sorted(z)==true && is_sorted(k)==true && is_sorted(x)==true && is_sorted(r)==true) {
        return EXIT_SUCCESS;
    }
    else {
        return EXIT_FAILURE;
    }

}