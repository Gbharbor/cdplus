#include <iostream>
using namespace std;

int main() {

    // ======================================================
    // EXEMPLO 1 - SWITCH PARA DIAS DA SEMANA
    // ======================================================
    int dia;

    cout << "Digite um numero de 1 a 7 para o dia da semana: ";
    cin >> dia;

    switch (dia) {

        case 1:
            cout << "Domingo" << endl;
            break;

        case 2:
            cout << "Segunda-feira" << endl;
            break;

        case 3:
            cout << "Terca-feira" << endl;
            break;

        case 4:
            cout << "Quarta-feira" << endl;
            break;

        case 5:
            cout << "Quinta-feira" << endl;
            break;

        case 6:
            cout << "Sexta-feira" << endl;
            break;

        case 7:
            cout << "Sabado" << endl;
            break;

        default:
            cout << "Numero invalido! Digite um numero de 1 a 7." << endl;
    }

    cout << endl;


    // ======================================================
    // EXEMPLO 2 - SWITCH DENTRO DE LOOP
    // ======================================================
    for (int i = 0; i < 2; i++) {

        int escolha;

        cout << "Escolha 1 ou 2: ";
        cin >> escolha;

        switch (escolha) {

            case 1:
                cout << "Voce escolheu a opcao 1." << endl;
                break;

            case 2:
                cout << "Voce escolheu a opcao 2." << endl;
                break;

            default:
                cout << "Opcao invalida." << endl;
        }

        cout << endl;
    }


    // ======================================================
    // EXEMPLO 3 - SWITCH SIMPLES
    // ======================================================
    int x;

    cout << "Digite um valor para x (10 ou 20): ";
    cin >> x;

    switch (x) {

        case 10:
            cout << "x e igual a 10" << endl;
            break;

        case 20:
            cout << "x e igual a 20" << endl;
            break;

        default:
            cout << "x nao e 10 nem 20" << endl;
    }

    cout << endl;

    return 0;
}