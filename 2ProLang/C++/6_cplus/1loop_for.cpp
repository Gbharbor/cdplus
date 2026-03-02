#include <iostream>
using namespace std;

int main () {
    cout<<"EX 1: repeticao de frase\n";
    for (int controle = 0; controle <=30; controle++) {
        cout<<"Esta frase se repetira ate q a variavel controle seja maior dq 30\n";
        cout<<"Controle= "<<controle<<"\n";
    }
    cout<<endl;//separar exemplos

    cout<<"EX 2: incremento e decremento\n";
    cout<<"Contando de 1 a 5"<<endl;
    for(int i=1; i<=5; i++) {
        cout<<"i= "<<i<<endl;
    }
    cout<<"contando de 5 a 1"<<endl;
    for(int k=5; k>=1; k--) {
        cout<<"k= "<<k<<endl;
    }
    cout<<endl;

    cout<<"EX 3: Soma dos numeros de 1 a 10\n";
    int soma = 0;
    for (int p=1; p<=10; p++) {
        soma +=p; // += é diferente de ++
    }
    cout<<"A soma dos numeros de 1 a 10 é: "<<soma<<endl;
    cout<<endl;

    cout<<"EX 4: Numeros pares de 1 a 10\n";
    for (int i=2; i<=10; i+=2) {
        cout<<i<<" "; 
    }
    cout<<endl;

    cout<<"EX 5: Tabela de multiplicacao por 2\n";
    for (int i=1; i<=10; i++) {
        cout<<i<<"x2 = "<<i*2<<endl;
    }
    cout<<endl;

    cout<<"EX 6: Sequencia de Fibonacci(10 termos)\n";
    int a=0, b=1, next;
    cout<<a<<" "<<b<<" ";//1 e 2 termo ja tao aqui, por isso i comeca c/3 
    for (int i=3; i<=10; i++) {
        next = a + b; //calcula o prox termo da sequencia
        cout<<next<<" ";
        a = b; //atualiza os valores p/ o prox calc
        b = next;
    }
    cout<<endl;

    return 0;
}