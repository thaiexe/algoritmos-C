/*
Suponha que o número de andares de uma coleção de n ≥ 1
prédios, todos numa mesma rua, seja dado por um vetor de ints não-negativos.
Por exemplo, o vetor (10, 20, 12, 15, 17) representa um perfil no qual o primeiro
prédio tem 10 andares, o segundo, 20 andares, e assim sucessivamente. Admita
que uma nova lei foi aprovada na cidade que obriga que todos os prédios de
uma mesma rua tenham o mesmo número de andares. Neste problema você vai
escrever um programa que recebe um vetor como acima, e devolve o número
mínimo de andares que devem ser construídos para satisfazer esta nova lei.
*/

#include <iostream>

using namespace std;

int maiorAndar(int v[], int a)
{
    int nMaior = 0;

    for(int i = 0; i < a; i++)
    {
        if(v[i] > nMaior)
        {
            nMaior = v[i];
        }
    }
    return nMaior;
}


int main()
{   
    int p[] = {10, 17, 12, 15, 20, 45, 7};
    int elementos = sizeof(p) / sizeof(int);

    cout << "\nO maior andar e: " << maiorAndar(p, elementos) << "\n";
    int resp[elementos];

    for(int i = 0; i < elementos; i++)
    {
        resp[i] = maiorAndar(p, elementos) - p[i];
        cout << "A quantidade de andares que devera ser contruido no " 
             << i + 1 << " predio sera de: "
             << resp[i] << " andares \n";
    }
   
    return 0;
}