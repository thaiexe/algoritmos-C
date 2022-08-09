#include <iostream>
#include <cstdlib>

using namespace std;

using stack_type = int *;

stack_type make_stack(int n) {
    int *stack = new int[n+2];
    if (stack == nullptr) {
        cerr << "Não há memória suficiente!!\n";
        exit(1);
    }
    stack[0] = 0; // numero de elementos na pilha
    stack[1] = n; // numero maximo de elementos na pilha
    return stack;
}

bool empty(stack_type stack) {
    return stack[0] == 0;
}
 
void push(stack_type stack, int x) {
    if (stack[0] == stack[1]) {
        cerr << "Stack overflow!";
        exit(2);
    }  
    ++stack[0];
    stack[stack[0] + 1] = x;
}

int top(stack_type stack) {
    if (stack[0] == 0) {
        cerr << "Stack underflow!";
        exit(3);
    }
    return stack[stack[0] + 1];
}

void pop(stack_type stack) {
    if (stack[0] == 0) {
        cerr << "Stack underflow!";
        exit(3);
    }
    --stack[0];
}

int size(stack_type stack) {
    return stack[0];
}

void destroy_stack(stack_type stack) {
    delete [] stack;
}

// recebe v[b:e), com e > b e rearranja
// v[b:e) de tal forma que
// v[b:i) <= v[i] < v(i:e) para algum i em [b:e)
// e devolve i
int partition(int *v, int b, int e) {
    const int pivo = v[b];
    int i = b;
    for (int j = b+1; j < e; ++j)
        if (v[j] <= pivo) {
            ++i;
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
        }
    v[b] = v[i]; v[i] = pivo;
    return i;
}

// recebe v[b:e) com e >= b e rearranja v[b:e)
// de tal forma que v[b] <= v[b+1] <= ... <= v[e-1]
void qsort_it(int *v, int b, int e) {
    if (e - b <= 1) return;
    stack_type stack = make_stack(e - b);
    push(stack, b); push(stack, e);
    while (!empty(stack)) {
        e = top(stack); pop(stack);
        b = top(stack); pop(stack);
        int i = partition(v, b, e);
        if (i - b > 1) {
            push(stack, b); push(stack, i);
        } 
        if (e - i - 1 > 1) {
            push(stack, i+1); push(stack, e);
        }
    }
    destroy_stack(stack);
}

void subst_stack(int *v, int b, int e, int x, int y ){
    if(e-b == 0) return;

    stack_type stack = make_stack(e-b+1);
    push(stack, b); push(stack,e);
    while (!empty(stack))
    {
        e = top(stack); pop(stack);
        b = top(stack); pop(stack);
        if(e - b == 1 ){

            if(v[b] == x) v[b] = y;

        } else {
            int m = (b + e) / 2;
            push(stack, b); push(stack,m);
            push(stack, m); push(stack,e);
        }
    }
    destroy_stack(stack);
    
}

int main() {
    int v[] = {1,2,3,2,5,6,2,8,9};

    subst_stack(v,0,9,2,10);


   for (int x: v) cout << x << ' ';
    

}

// int main() {
//     const int MAX = 100;
//     int v[MAX];
//     for (int i = 0; i < MAX; ++i)
//         v[i] = rand() % 100;
//     qsort_it(v, 0, MAX);
//     for (int i = 0; i < MAX; ++i) cout << v[i] << ' ';
//     cout << '\n';
// }
/*int main() {
    stack_type s = make_stack(10);
    for (int i = 0; i < 10; ++i) push(s, i);
    while (!empty(s)) {
        cout << top(s) << ' ';
        pop(s);
    }
}*/