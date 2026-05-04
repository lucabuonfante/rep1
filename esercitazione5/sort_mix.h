#include <vector>
#include "ordinamento.h"
#include <cmath>


template <typename T> /* le funzioni che agiscono per 
riferimento le ho messe come void, altrimenti creano una copia*/
void sort_mix( std::vector<T> &vec) {
    int l=size(vec);
    if (l<215) {
        ins_sort(vec); /*
        ho modificato l'insertion sort per farlo 
        agire sul riferimento*/
        
    }
    else {
        quicksort(vec, 0, l-1);
        
    }
}