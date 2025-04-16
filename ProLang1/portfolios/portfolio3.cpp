/*
Escreva um programa utilizando a linguagem C++ que leia as medidas dos lados de um triângulo e escreva se ele é Equilátero, Isósceles ou Escaleno. Sendo que:
Triângulo Equilátero: possui os 3 lados iguais. 
Triângulo Isóscele: possui 2 lados iguais. 
Triângulo Escaleno: possui 3 lados diferentes.
O programa deve apresentar um menu com as opções dentro de uma estrutura de repetição
1 Verificar triangulo que encaminhará para leitura dos lados
2 sair que fechará o programa
*/

//OPCAO 1
#include <iostream>
using namespace std;

int main() {
    int opcao; // Variável para armazenar a opção do menu
    double lado1, lado2, lado3; // Variáveis para os lados do triângulo

    do {
        // Exibe o menu
        cout << "\nMenu:\n";
        cout << "1. Verificar tipo de triângulo\n";
        cout << "2. Sair\n";
        cout << "Escolha uma opção (1-2): ";
        cin >> opcao;

        switch (opcao) {
            case 1: // Opção para verificar o tipo de triângulo
                // Leitura dos lados do triângulo
                cout << "Digite o comprimento do primeiro lado: ";
                cin >> lado1;
                cout << "Digite o comprimento do segundo lado: ";
                cin >> lado2;
                cout << "Digite o comprimento do terceiro lado: ";
                cin >> lado3;

                // Verifica se os lados formam um triângulo válido
                if (lado1 <= 0 || lado2 <= 0 || lado3 <= 0 || 
                    (lado1 + lado2 <= lado3) || 
                    (lado1 + lado3 <= lado2) || 
                    (lado2 + lado3 <= lado1)) {
                    cout << "Os valores informados não formam um triângulo válido." << endl;
                } else {
                    // Determina o tipo do triângulo
                    if (lado1 == lado2 && lado2 == lado3) {
                        cout << "O triângulo é Equilátero." << endl;
                    } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
                        cout << "O triângulo é Isósceles." << endl;
                    } else {
                        cout << "O triângulo é Escaleno." << endl;
                    }
                }
                break;

            case 2: // Opção para sair
                cout << "Saindo do programa. Até logo!" << endl;
                break;

            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }

    } while (opcao != 2); // Continua o loop até que o usuário escolha sair

    return 0;
}

//OPCAO 2 : 
#include <iostream>
using namespace std;

int main() {
    int opcao; // Variável para armazenar a opção do menu
    double lado1, lado2, lado3; // Variáveis para os lados do triângulo

    do {
        // Exibe o menu
        cout << "\nMenu:\n";
        cout << "1. Verificar tipo de triângulo\n";
        cout << "2. Sair\n";
        cout << "Escolha uma opção (1-2): ";
        cin >> opcao;

        if (opcao == 1) { // Opção para verificar o tipo de triângulo
            // Leitura dos lados do triângulo
            cout << "Digite o comprimento do primeiro lado: ";
            cin >> lado1;
            cout << "Digite o comprimento do segundo lado: ";
            cin >> lado2;
            cout << "Digite o comprimento do terceiro lado: ";
            cin >> lado3;

            // Determina o tipo do triângulo
            if (lado1 <= 0 || lado2 <= 0 || lado3 <= 0) {
                cout << "Os valores informados não podem ser negativos ou zero." << endl;
            } else if (lado1 == lado2 && lado2 == lado3) {
                cout << "O triângulo é Equilátero." << endl;
            } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
                cout << "O triângulo é Isósceles." << endl;
            } else {
                cout << "O triângulo é Escaleno." << endl;
            }
        } else if (opcao == 2) { // Opção para sair
            cout << "Saindo do programa. Até logo!" << endl;
        } else {
            cout << "Opção inválida! Tente novamente." << endl;
        }

    } while (opcao != 2); // Continua o loop até que o usuário escolha sair

    return 0;
}