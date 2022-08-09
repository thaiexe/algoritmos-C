#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// Recebe n >=2, recebe p[0:x), com x >= log de n
// e devolve em p a decomposição em fatores primos
// de n.
int* fatPrimes(int n, int p[], int k=0, int d =2){

    if (n == 1){
        p[k] = 0;

        return p;
    }

    int rest = n % d;
    int result = n / d;

    if(rest == 0){
        p[k] = d;

        fatPrimes(result,p,k+1,d);
    }else{
        
        fatPrimes(n,p,k,d+1);
    }
}

int main(){

    int n = 60;
    int k = round(log(n));
    int p[k];
    
    fatPrimes(n,p);

    for(int i =0; i <= k; i++){
        cout << p[i] << '\n';
    }
}