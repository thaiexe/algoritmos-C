
#include <iostream>
#include <cstdlib>

using namespace std;


void replace_(int *v, int b, int e, int x, int y ){

    if(e -b == 0) return;

    if(v[e-1] == x) {
        v[e-1] = y; 
    }
    replace_(v, b, e-1, x, y);
}

void replace_t(int *v, int n, int x, int y ){

    if( n < 1) return;

    if(v[n-1] == x) {
        v[n-1] = y; 
    }
    replace_t(v, n-1, x, y);
}

void replace_div(int *v, int b, int e, int x, int y) {
    if(e - b == 0) return;
    if(e - b == 1) {
        if(v[b] == x) v[b] = y;
        return; 
    }

    int  m = (b + e) / 2;
    replace_div(v,b,m,x,y);
    replace_div(v,m, e, x, y);
}

void replace_tc(int *v, int b, int e, int x, int y) {
    
    while (e - b >= 2)
    {
        if(e - b == 0) return;
        if(e - b == 1) {
            if(v[b] == x) v[b] = y;
            return; 
        }

        int  m = (b + e) / 2;
        replace_div(v,b,m,x,y);
        b = m;
    }
    
}

int soma(int *v, int b, int e){

    if (b == e) return 0;
    if (e - b == 1) return v[b];
    int m = (b +e)/2;
    return soma(v, b, m) + soma(v, m, e);
}

int soma_tc(int *v, int b, int e, int acc){
    return e - b == 0 ? acc :soma_tc(v, b+1, e, acc+v[b]);
}

int max(int v[], int n) {
    if(n == 1) return v[0];
    int x = max(v, n-1);
    return x >= v[n-1] ? x : v[n-1];
}

int max_ (int x, int y) { return x >= y ? x: y;}

int max_tc (int *v, int b, int e, int acc){
    

    return e - b == 0 ? acc: max_tc(v, b+1, e, max_(v[b],acc));
}

int main() {
    int v[] = {1,2,3,2,5,6,2,8,9};

    // replace_(v, 0, 9, 2, 10);
    // replace_t(v,9,2,10);
    // replace_tc(v,0,9,2,10);
    // int x = soma_tc(v,0,9,0);


//    for (int x: v) cout << x << ' ';
    
}
