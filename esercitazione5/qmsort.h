
#include<vector>
#include<cmath>


template<typename T>
void merge(std::vector<T> &A, int p, int q, int r) {
    // p,q,r "partono da 0"
    int n1=q-p+1;
    int n2=r-q;
    std::vector<T> L(n1); //se uso il flag VLA (variable length array) mi dà problemi qui e devo usare un vettore
    std::vector<T> R(n2);
    //copiamo gli elementi di A dentro L e R
    for (int i=0; i<=n1-1; i++) {
        L[i]=A[p+i];
    }

    for (int j=0; j<=n2-1; j++) { /*il primo elemento di R è il 
        q+1 - esimo elemento di A*/ 
        R[j]= A[q+j+1];
    }
    
    int i=0;
    int j=0;
    while (i+j+p<=r)  {

        if (i<n1) { /* in questo modo si controlla prima 
            che i e j siano ammissibili e poi si confrontano 
            L[i] e R[j]. così questi due hanno sempre senso*/
            if (j>=n2) {
            A[i+j+p]=L[i];
            i=i+1;
            }

            else if (L[i]<=R[j]) {
               A[i+j+p]=L[i];
            i=i+1; 
            }
            else{ /* se sono entrambi ammissibili e
                R[j]<L[i] metto R[j] in A*/
               A[i+j+p]=R[j];
                j=j+1; 
            }
        }
        else { /* se i>=n1 e i+j+p<r, sicuramente
            j<n2, quindi metto R[j]  in A*/
            A[i+j+p]=R[j];
            j=j+1;
        }
    }
    
}

template <typename T>
void mergesort (std::vector<T> &A, int p, int r) {
    //usiamo il riferimento per non dover creare ogni volta una cpia del vettore
    if (p<r) {
        int q=floor((p+r)/2); //parte intera
        mergesort (A,p,q);
        mergesort (A,q+1,r);
        merge(A,p,q,r);
    }
   
}




template <typename T>
int partition (std::vector<T> &A, int p, int r) {
    T x = A[r];
    int i= p-1;
    for (int j=p; j<=r-1; j++) {
        if (A[j]<=x) {
            i=i+1;
            //exchange:
            T c=A[j];
            A[j]=A[i];
            A[i]=c;
        }
        else{}
    }
    //exchange:
    T c=A[i+1];
    A[i+1]=A[r];
    A[r]=c;
    return i+1;
}

template<typename T>
void quicksort(std::vector<T> &A, int p, int r) {
    if (p<r) {
        int q=partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }

}


