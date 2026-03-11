#include <iostream>
using namespace std;

int main() {

    // ======================================================
    // EXEMPLO 1 - CONTAGEM DE 1 A 5
    // ======================================================
    cout << "EXEMPLO 1: Contagem de 1 a 5 usando do...while\n";

    int i = 1;

    // O bloco executa primeiro, depois verifica a condição
    do {
        cout << "i = " << i << endl;
        i++;
    } while (i <= 5);

    cout << endl;


    // ======================================================
    // EXEMPLO 2 - VALIDACAO DE ENTRADA
    // ======================================================
    cout << "EXEMPLO 2: Solicitar entrada do utilizador\n";

    int numero;

    do {
        cout << "Digite um numero positivo: ";
        cin >> numero;
    } while (numero <= 0);  // continua enquanto o numero nao for positivo

    cout << "Voce digitou: " << numero << endl;

    cout << endl;


    // ======================================================
    // EXEMPLO 3 - MENU DE OPCOES
    // ======================================================
    cout << "EXEMPLO 3: Menu de opcoes\n";

    int opcao;

    do {
        cout << "\nMenu de opcoes:\n";
        cout << "1. Opcao 1\n";
        cout << "2. Opcao 2\n";
        cout << "3. Sair\n";

        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1:
                cout << "Voce escolheu a opcao 1.\n";
                break;

            case 2:
                cout << "Voce escolheu a opcao 2.\n";
                break;

            case 3:
                cout << "Saindo do menu...\n";
                break;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 3); // repete ate o utilizador escolher sair

    cout << endl;


    // ======================================================
    // EXEMPLO 4 - TABUADA
    // ======================================================
    cout << "EXEMPLO 4: Tabuada\n";

    int numeroTabuada;
    int j = 1;

    cout << "Digite um numero para ver sua tabuada: ";
    cin >> numeroTabuada;

    do {
        cout << numeroTabuada << " x " << j
             << " = " << numeroTabuada * j << endl;

        j++;

    } while (j <= 10);

    cout << endl;

    return 0;
}