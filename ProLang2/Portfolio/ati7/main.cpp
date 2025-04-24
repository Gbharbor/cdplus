// main.cpp
#include <iostream>
#include "calc.h"
using namespace std;

int main() {
    float num1, num2;
    int opcao;

    cout << "Digite o 1 número: ";
    cin >> num1;
    cout << "Digite o 2 número: ";
    cin >> num2;

    cout << "\nEscolha uma operação:\n";
    cout << "1. Soma\n";
    cout << "2. Subtração\n";
    cout << "3. Multiplicação\n";
    cout << "4. Divisão\n";
    cout << "Opção: ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            cout << "Resultado da soma: " << soma(num1, num2) << endl;
            break;
        case 2:
            cout << "Resultado da subtração: " << subtracao(num1, num2) << endl;
            break;
        case 3:
            cout << "Resultado da multiplicação: " << multiplicacao(num1, num2) << endl;
            break;
        case 4:
            cout << "Resultado da divisão: " << divisao(num1, num2) << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
    }

    return 0;
}