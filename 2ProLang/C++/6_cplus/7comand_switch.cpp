#include <iostream>
using namespace std;
 int main() {
    int dia;
    cout<<"digote um numero de 1 a 7 para o dia da semana";
    cin>>dia;
    //switch comum
    switch(dia) {
        case1:
            cout<<"domingo"<<endl;
            break;
        case2:
            cout<<"Segunda"<<endl;
            break;
        case3:
            cout<<"terca"<<endl;
            break;
        case4:
            cout<<"quarta"<<endl;
            break;
        case5:
            cout<<"quinta"<<endl;
            break;
        case6:
            cout<<"sexta"<<endl;
            break;
        case7:
            cout<<"sexta"<<endl;
            break;
        default:
            cout<<"Numero invalida ! digite um numero de 1 a 7"<<endl;
    }
    cout<<endl;
    
    //switch em loops aninhados
    for (int i=0; i<2; i++) {
        int escolha;
        cout<<"Escolha 1 ou 2: ";
        cin>> escolha; 
        switch(escolha) {
            case1:
                cout<<"vc escolheu 1"<<endl;
                break;
            case2:
                cout<<"vc escolheu 2"<<endl;
                break;
            default:
                cout<<"opcao invalida"<<endl;
        }
        cout<<endl;
    }
    //Outra estrutura para switch
    int x;
    cout<<"digite um valor para x(10 ou 20): ";
    cin>> x;
    switch(x) {
        case 10:
            cout<<"x e igual a 10"<<endl;
            break;
        case 20:
            cout<<"x e igual a 20"<<endl;
            break;
        default:
            cout<<"x n e 10 nem 20"<<endl;
            break;
    }
    cout<<endl;
    return 0;
}