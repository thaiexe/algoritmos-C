#include <iostream>
#include <cstdlib>

using namespace std;


/*HEAPSORT*/
void sift_down(int *v, int n, int i) {
    while (2*i + 1 < n )
    {
        int k = 2*i + 1;
        if(k+1 < n && v[k+1] > v[k]) ++k;
        if(v[i] >= v[k]) return;
        int tmp = v[i]; v[i] = v[k]; v[k] =tmp;

        i = k;
    }
    
}

void build_heap(int *v, int n) {
    for (int i = (n-1)/2; i >=0; --i)
    {
        sift_down(v,n,i);
    }
    
}

void hsort(int *v, int n) {
    build_heap(v,n);

    while(n > 1) {
        --n;
        int tmp = v[n];
        v[n] = v[0];
        v[0] = tmp;
        sift_down(v,n,0);
    }
}

/*QUICKSORT*/

int partition (int *v, int b, int e) {

    int pivo = v[b];
    int i = b;

    for(int j = b+1; j < e; ++j) {
        if(v[j] <= pivo) {
            ++i;
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
        }
    }
    v[b] = v[i]; v[i] = pivo;
    return i;
}

// recebe v[b:e) com e>= b e rearranja v[b:e)
// de tal forma que v[b] <= v[b+1] <= ... <= v[e-1]
void qsort(int *v, int b, int e) {
    if(e - b <= 1) return;
    int  i = partition(v, b, e);
    qsort(v,b,i);
    qsort(v,i+1, e);
}

void qsort_tc_(int *v, int b, int e) {
    
    while (e - b >= 2)
    {
        int  i = partition(v, b, e);
        qsort(v,b,i);
        b = i+1;
    }
    
}

void qsort_tc(int *v, int b, int e) {
    
    while (e - b >= 2)
    {
        int  i = partition(v, b, e);
        if(i -b <= e - i - 1){
            qsort(v,b,i);
            b = i+1;
        } else {
            qsort(v,i + 1, e);
            e = i;
        }
        
    }
    
}



int main() {
    
    int v[] = {3, 6, 8, 2, 1, 4, 9, 5, 7, 10};
    qsort(v,0,10);
    for (int x: v) cout << x << ' ';
    return 0;
}