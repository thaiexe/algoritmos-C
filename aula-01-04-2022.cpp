#include <iostream>

using namespace std;

int fat(int n) {
    return n == 0
           ? 1
           : n * fat(n -1);
}

int soma(int n) {

    return n == 0
           ? 0 
           : n + soma(n-1);
}

int fib(int n) {
    return n == 0 || n == 1
           ? n
           : fib(n-1) + fib(n+2);
}

// Escreva uma função que recebe um int n>=0
// e escreve os números de 1 até n.
// "pequeno" n == 0
// "grande" n > =0 

void escreve(int n) {
    if(n == 0) return;
    escreve(n-1);
    // suponha que a função faz o que promete,
    //ou seja, escreve os números 1,2, ..., n-1
    //Logo, falta só escrever o n
    cout << n << ' ';
}

//recebe n >=0 e escreve n, n-1, ..., 1
void esc_inv(int n) {
    if (n == 0) return;
    cout << n << ' ';
    esc_inv(n-1);
}

// Recebe um vetor v[0:n) de ints, com n >= 0,
// e devolve a soma dos elementos de v[0:n)
int soma(int v[], int n) {
    return n == 0
           ? 0
           : soma(v, n-1) + v[n-1];
}

//Recebe um vetor v[0:n) de ints, com n>= 0,
// e devolve a soma dos elementos pares de v[0:n)
int somaPar(int v[], int n) {
    
    if(n == 0) return 0;
        
    int resto = v[n-1] % 2;

    if(resto == 0){
        return somaPar(v, n-1) + v[n-1];
    }else{
        return somaPar(v,n-1);
    }
}

// recebe v[0:n), com n > 0, e devolve um elemento
// máximo de v[0:n)
int max(int v[], int n) {
    if(n == 1) return v[0];
    int x = max(v, n-1);
    return x >= v[n-1] ? x : v[n-1];
}
int main()
{   
     int v[] = {1,2,3,4,5,6,7,8,9};
    cout<< fat(6) << '\n';
    //cout<< soma(100) << '\n';
    //cout << somaPar(v,9);
   // escreve(10);
     //esc_inv(10);

}