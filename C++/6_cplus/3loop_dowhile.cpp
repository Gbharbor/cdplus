#include<iostream>
using namespace std;

int main () {
    cout<<"EX1: contagem de 1 a 5 usando do while:"<<endl;
    int i = 1;
    //o do while continua enquanto i for menor ou igual a 5
    do {
        cout<<"i = "<<i<<endl;
        i++;
    } while(i <=5);
    cout<<endl;

    cout<<"EX2: Solicitar entrada de usuario:"<<endl;
    int numero;
    do {
        cout<<"Digite um numero positivo: ";
        cin>>numero;
    } while (numero <= 0);//continua solicitando ate q o numero seja positivo
    cout<<"vc digitou: "<<numero<<endl;//exibe o numero positivo digitado.
    cout<<endl;

    cout<<"EX3: Menu de Opcoes"<<endl;
    int opcao;
    do {
        cout<<"menu de opcoes: "<<endl;
        cout<<"1. Opcao 1"<<endl;
        cout<<"2. Opcao 2"<<endl;
        cout<<"3. Sair"<<endl;
        cout<<"escolha uma opcao: ";
        cin>>opcao; //le a opcao do user

        switch(opcao) {
            case 1:
                cout<<"Vc escolheu a opcao 1."<<endl;
                break;
            case 2:
                cout<<"Vc escolheu a opcao 2."<<endl;
                break;
            case 3:
                cout<<"Saindo do menu..."<<endl;
                break;
            default:
                cout<<"Opcao invalida. try again"<<endl;
        }
    } while(opcao !=3);//continua ate q o user escolha sair
    cout<<endl;
    
    cout<<"EX4 : Tabuada"<<endl;
    int numeroTabuada, j = 1;
    cout<<"Digite um numero para ver sua tabuada: ";
    cin>>numeroTabuada;
    do {
        cout<<numeroTabuada<<" x "<<j<<" = "<<numeroTabuada * j<<endl; 
        j++;
    } while (j<=10);
    cout<<endl;

    return 0;
}