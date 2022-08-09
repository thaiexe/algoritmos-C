#include <iostream>

using namespace std;

// Gera as instruções para mover
// n >= 1pinos de A para C usando B como auxiliar
// e devolve o comprimento desta sequencia de instruções
int hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << A << "->" << C << '\n';
        return 1;
    }
    else {
        int k1 = hanoi(n-1, A, C, B);
        cout << k1 << '\n';
        cout << A << "->" << C << '\n';
        int k2 = hanoi(n-1, B, A, C);
        cout << k2 << '\n';
        return k1 + k2 + 1;
        
    }
}

// Recebe um vetor v[b:e] de ints, com b <= e e
// devolve a soma de elementos de v[b:e)
// e-b é o numero de elementos do intervalo [b:e)
int sum(int v[], int b, int e) {

    if (b == e) return 0;
    if (e - b == 1) return v[b];
    int m = (b +e)/2;
    return sum(v, b, m) + sum(v, m, e);
}
// Recebe um vetor v[b:e) de ints, com b <= e, e um int key
// e devolve true se, e só se, key é um dos elementos de
// v[b:e)

bool contains(int v[], int b, int e, int key) {
    if (b == e ) return false;
    if (e - b == 1 ) return v[b] == key;
    int m = (b + e )/2;
    return contains(v, b, m, key) || contains(v, m, e, key);
}
// Recebe um vetor v[b:e) de ints em ordem não-decrescentes
// e devolve true se, e só, key é um dos elementos de v[b:e)
bool bsearch(int v[], int b, int e, int key){
    if(b == e ) return false;
    int m = ( b + e ) / 2;
    if(v[m] == key) return true;
    return key < v[m]
                ? bsearch(v, b, m, key)
                : bsearch(v, m+1, e, key);

}
int main()
{
   int comprimento = hanoi(4,'A','B','C');
   cout << comprimento << '\n';

   //int v[] = {1,2,3,5,2,8,9};

   //cout << sum(v,0,7) << '\n';

   //cout << contains(v, 0, 7, 10);

   //int w[] = {1,4,5,7,8,12,16,19,20};
   //cout << bsearch(w, 0, 9, 16);
   //cout << bsearch(w, 0, 9, 0);

}