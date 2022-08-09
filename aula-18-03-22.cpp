#include <iostream>
#include <string>

using namespace std;

// recebe uma string s e devolve o seu comprimento
//size_t é um tipo inteiro não negativo
size_t len(const char *s) {
    
    size_t n = 0;
    
    while(*s != '\0') {
        ++s;
        ++n;
    }
    
    return n;
}

size_t len3(const char *s) {

    const char *t = s;

     cerr << *t << '\n';
      cerr << t<< '\n';
    while(*t++);
    return t-s-1;
}

char *cpy(char *destino, const char *fonte){

    char *inicio = destino;
    while(*fonte){
        *destino = *fonte;
        ++fonte; ++destino;
    }
    *destino = '\0';
    return inicio;
}

// devolve true se s é um prefixo de t

bool is_pref(const char *s, const char *t) {

    while(*s && *s == *t){
        ++s; ++t;
    }
    return *s == '\0';
}

int main()
{
    /*String*/
       const char t[] = "123";
   /*Vetor de caracteres*/
//   char v[] = {'f','a','t','e','c'};
   /*String vetor*/
//   char z[] = {'f','a','t','e','c','\0'};


  size_t sub_memoria = len3(t);
  cout << sub_memoria << '\n';

    // char v[2];
    // const char *msg = "ola, bom dia";
    // cpy(v, msg);

    // cout << v << "\n";
    // printf("a string %s tem comprimento de %ld \n",cpy(v,msg), len(msg));

    // const char *a = "dsds";
    // const char *b = "dsdsds";
    // cout << is_pref(a, b) << "\n";
    // char t[100] = "1234567";
    // cout << len3(t) << "\n";
}
