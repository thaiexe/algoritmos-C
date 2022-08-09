#include <iostream>

using namespace std;

// recebe um vetor v[b:e) de inteiros, um int n para quantidade
// de elementos em v[b:e), um int k e devolve a soma dos elementos 
// em v[b:e) que são maiores que k.(versão iterativa) 
int somaMaiorQue_i(int *v, int n, int k){

    int soma = 0;
    for(int i = 0; i < n; ++i) {
       
        if(v[i] > k ) {
            soma = v[i] + soma;
        }
    }

    return soma;  
    
}

// recebe um vetor v[b:e) de inteiros, um int n para quantidade
// de elementos em v[b:e), um int k e devolve a soma dos elementos 
// em v[b:e) que são maiores que k.(versão recursiva)
int somaMaiorQue(int *v, int n, int k){

    if(n == 0) return 0;
    if(v[n-1] > k){
        return somaMaiorQue(v, n-1,k) + v[n-1];
    }else{
        return somaMaiorQue(v,n-1,k);
    }
    
    
}

// recebe um int x, um int y 
// e devolve o maior entre eles.
int maior (int x, int y) { return x >= y ? x: y;}
// recebe um vetor v[b:e) de inteiros, um int n para quantidade
// de elementos em v[b:e), um int k, um int acc que recebe valor inicial 0
// e devolve a soma dos elementos em v[b:e) que
//  são maiores que k.(versão recursiva em cauda)
int somaMaiorQue_tc(int *v, int n, int k, int acc){
    return n == 0 ? acc: somaMaiorQue_tc(v, n-1,k, acc = acc+ maior(k, v[n-1]));
}

// recebe um vetor v[b:e), com e maior que b
// e devolve true se os elementos no vetor for 
// uma sequência sinal-alternante, caso contrário
//  devolve falso.(versão iterativa)
bool alternante_i(int *v, int b, int e){

    int anterior = v[b];
    for(int i = b+1; i < e; ++i){

        if(anterior > 0 && v[i] > 0 || anterior < 0 && v[i] < 0) return false;

        anterior = v[i];
    }

    return true;
}




int main(){

    int v[] = {1,5,3,8,4,9,10,75};
    int v_alter[] = {1, -1, 2, -4, 5};

    // int soma  = somaMaiorQue_i(v,8, 0);
    // int soma  = somaMaiorQue(v,8, 0);
    // int soma  = somaMaiorQue_tc(v,8, 0,0);
    // cout << soma << ' ';

    cout << alternante_i(v_alter, 0, 5)<< ' ';

}