#include <iostream>

#include "vector"
#include "ordinamento.h"

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
    std::vector<std::string> w=ins_sort(vec);
    std::vector<std::string> z=sel_sort(vec);
    
    if (is_sorted(v)==true && is_sorted(w)==true &&  is_sorted(z)==true) {
        std::cout << "i vettori sono tutti ordinati \n";
    }
    else {
        std::cout << "c'è un problema \n";
    }

}