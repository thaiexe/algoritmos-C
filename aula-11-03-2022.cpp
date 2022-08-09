#include <iostream>

using namespace std;

void exch(int *x, int *y) {
    int tmp = *x;

    *x = *y;
    *y = tmp;

}

// recebe um vetor v[0:n), n >= 0 de ints e devolve
// a soma dos elementos de v[0:n) 
int sumvl(int v[], int n) {

    int acc = 0;
    for(int i = 0; i< n; ++i)
        acc +=v[i];
    return acc;
}

// recebe begin, end: int * tais que [begin:end)
// é valido begin <= end e devolve a soma 
// dos elementos *begin, *(begin+1), ..., *(end-1)

int sum(int *begin, int *end) {

    int acc = 0;
    while (begin != end){

        acc += *begin;
        ++begin;
    }

    return acc;
}

// abreviatura: escrever *[begin:end)
// é o mesmo que *begin, (*begin +1), ..., *(end -1)
// recebe begin <= end e devolve a soma
// dos elementos pares de *[begin:end)


int sum_pairs(int *begin, int *end) {

    int acc = 0;

    while (begin != end)
    {
        int pair = *begin % 2;
        if(pair == 0) {
            acc += *begin;
        }
        
        ++begin;
    }
    
    return acc;
}
int main() {

    int r=10, s=20;

    cout << r <<"-"<< s <<'\n';
    exch(&r,&s);
    cout << r <<"-"<< s <<'\n';

    int v[] = {1, 3, 4, 5, 2, 7};
    int sm = sum_pairs(v, v+6);
    cout << sm << '\n';

}

