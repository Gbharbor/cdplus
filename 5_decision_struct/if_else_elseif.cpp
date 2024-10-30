#include <iostream>

int main() {
    using namespace std;

    int idade;

    // Solicita ao usuário que insira sua idade
    cout << "Por favor, insira sua idade: ";
    cin >> idade;

    // Estrutura condicional if
    if (idade < 0) {
        cout << "Idade inválida!" << endl;
    } 
    // Estrutura condicional if-else
    else if (idade < 18) {
        cout << "Você é menor de idade." << endl;
    } 
    // Estrutura else
    else {
        cout << "Você é maior de idade." << endl;
    }

    // Exemplo de uso de else if para categorizar idades
    if (idade < 13) {
        cout << "Você é uma criança." << endl;
    } else if (idade < 20) {
        cout << "Você é um adolescente." << endl;
    } else if (idade < 65) {
        cout << "Você é um adulto." << endl;
    } else {
        cout << "Você é um idoso." << endl;
    }

    return 0; // Finaliza o programa
}
