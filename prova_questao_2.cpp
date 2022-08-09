
#include <iostream>

using namespace std;

// recebe v[0:n), com n > 0, e devolve um elemento
// máximo de v[0:n)
int max(int v[], int n) {
    if(n == 1) return v[0];
    int x = max(v, n-1);
    return x >= v[n-1] ? x : v[n-1];
}

int main () {
    int p[] = {10, 17, 12, 15, 20, 45, 7};
    const int elementos = sizeof(p) / sizeof(int);
    int maxAndar = max(p, elementos);
    int resp[elementos];
    
    cout << "\nO maior andar e: " <<  maxAndar << "\n";
    
    for(int i = 0; i < elementos; i++)
    {
        resp[i] = maxAndar - p[i];
        cout << "A quantidade de andares que devera ser contruido no " 
             << i + 1 << " predio sera de: "
             << resp[i] << " andares \n";
    }
}