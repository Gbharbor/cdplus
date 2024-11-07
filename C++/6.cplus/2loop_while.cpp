#include <iostream>
#include <cstdlib>//para o rand() e srand()
#include<ctime> //para o time()
using namespace std;

int main() {
    cout<<"EX1: Contando de 1 a 5\n";
    int i = 1; //inicia em 1, continua enquanto i<=5 for true.
    while(i<=5) {
        cout<<"i = "<<i<<endl;
        i++;
    }
    cout<<endl; //new line

    cout<<"EX2: Somando numeros ate um limite\n";
    int numero, soma = 0;
    cout<<"Digite numeros para somar(digite 0 para parar):"<<endl;
    while(true) {
        cin>>numero;
        if(numero == 0) {
            break;
        }
        soma+=numero; //add o numero a soma total
    }
    cout<<"a soma total é: "<<soma<<endl; //exibe a soma total;
    cout<<endl;

    
    cout << "EXEMPLO 3: Jogo de Adivinhação\n";
    srand(time(0));//Inicializa o gerador de numero aleatorio.
    int numeroSecreto = rand() % 100 + 1;//gera um numero secreto entre 1 e 100
    int palpite = 0;//inicializa o palpite do usuario
    cout<<"EX3: Adivinhe o numero entre 1 e 100"<<endl;
    //o palpite continua enquanto for diferente do numero secreto
    while(palpite != numeroSecreto) {
        cout<<"digite seu palpite: ";
        cin>>palpite;
        if(palpite < numeroSecreto) {
            cout<<"Mt baixo, tente de novo."<<endl;
        } else if (palpite > numeroSecreto) {
            cout<<"Mt alto, tente de novo."<<endl;
        } else {
            cout<<"Parabens, acertou !"<<endl;
        }
    }
    cout<<endl;
}