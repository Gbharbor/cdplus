#include<iostream> 
using namespace std;

int main() {
    cout<<"Uso do continue dentro de um loop for:\n";
    for (int i=0; i<10; i++) {
        if(i % 2 == 0) {
            continue; //pula os numeros pares
        }
        cout<<"i = "<<i<<endl; //imprime o valor de i se for impar
    }
    cout<<endl;

    cout<<"uso do contie em loops aninhados:\n";
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(j==1) {
                continue; //pula apenas o numero 1 e continua a iteracao.
            }
            cout<<"i= "<<i<<",j ="<<j<<endl;
        }
    }
    cout<<endl;

    cout<<"Uso do continue no laco for:\n";
    for(int i=0; i<5; i++) {
        if(i==2) { //se i for igual a 2 pula a iteracao atual
            continue;
        }
        cout<<"i= "<<i<<endl;
    }
    cout<<endl;
    return 0;
}
/*
Uso do continue dentro de um loop for:
i = 1
i = 3
i = 5
i = 7
i = 9
*/
/*
Uso do continue em loops aninhados:
i = 0, j = 0
i = 0, j = 2
i = 1, j = 0
i = 1, j = 2
i = 2, j = 0
i = 2, j = 2
*/
/*
Uso do continue no laço for:
i = 0
i = 1
i = 3
i = 4
*/