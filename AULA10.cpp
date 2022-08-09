#include <iostream>
#include <cstdlib>

using namespace std;

// Recebe um vetor v[0:n) e um indice i de [0:n)
// Tal que as subarvores esquerda e direita de i
// São heaps, e rearranja v[i:n) de tal forma
// Que a subarvore de raiz i é um heap
void siftdown(int *v, int n, int i) {
    while (2 * i + 1 < n) {
        int k = 2 * i + 1;
        if (k + 1 < n && v[k+1] > v[k]) ++k;
        if (v[i] >= v[k]) return;
        int tmp = v[i]; v[i] = v[k]; v[k] = tmp;
        i = k;
    }
}

void build_heap(int *v, int n) {
    for(int i = (n-1)/2; i >= 0; --i) {
        siftdown(v, n , i);
    }
}

void heap_sort(int *v, int n) {
    build_heap(v, n);
    while (n > 1) {
        --n;
        int tmp = v[n]; v[n] = v[0]; v[0] = tmp;
        siftdown(v, n ,0);
    }
}

// Dado um vetor v[b:e), com e > b,
// Rearranjar v[b:e) de tal forma que
// v[b:i) <= v[i] < v[i:e) para algum i em [b:e)
// E devolve i
int partition(int *v, int b, int e) {
    int pivo = v[b];
    int i = b;
    for (int j = b + 1; j < e; ++j) {
        if (v[j] <= pivo) {
            ++i;
            int tmp = v[i]; v[i] = v[j]; v[j] = tmp;
        }
    }
    v[b] = v[i]; v[i] = pivo;
    return i;
}

// Recebe v[b:e) com e >= b e rearranja v[b:e)
// De tal forma que v[b] <= v[b+1] <= .... <= v[e-]
void quicksort(int *v, int b, int e) {
    if (e - b <= 1) return;
    int i = partition(v, b, e);
    quicksort(v, b, i);
    quicksort(v, i+1, e);
}

int main() {
    int v[] = {5, 6, 9, 1, 3, 4, 2, 8, 7, 10};
    heap_sort(v, 10);
    // quicksort(v, 0, 10);
    for(int i = 0; i < 10; ++i) {
        cout << v[i] << " ";
    }
    return 0;
}