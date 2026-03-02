//EXEMPLO QUE ENVOLVE SWITCH, BREAK E CONTINUE
#include <iostream>
using namespace std;

int main() {
    int escolha;  // Variável para armazenar a escolha do usuário
    double num1, num2;  // Variáveis para armazenar os números a serem operados

    cout << "Bem-vindo à Calculadora Simples!" << endl;

    while (true) {  // Loop infinito para o menu
        cout << "\nEscolha uma operação:" << endl;
        cout << "1. Adição" << endl;
        cout << "2. Subtração" << endl;
        cout << "3. Multiplicação" << endl;
        cout << "4. Divisão" << endl;
        cout << "5. Sair" << endl;
        cout << "Digite sua escolha (1-5): ";
        cin >> escolha;

        switch (escolha) {  // Estrutura switch para as operações
            case 1:
                cout << "Digite dois números para adição: ";
                cin >> num1 >> num2;
                cout << "Resultado: " << (num1 + num2) << endl;
                break;  // Sai do switch

            case 2:
                cout << "Digite dois números para subtração: ";
                cin >> num1 >> num2;
                cout << "Resultado: " << (num1 - num2) << endl;
                break;  // Sai do switch

            case 3:
                cout << "Digite dois números para multiplicação: ";
                cin >> num1 >> num2;
                cout << "Resultado: " << (num1 * num2) << endl;
                break;  // Sai do switch

            case 4:
                cout << "Digite dois números para divisão: ";
                cin >> num1 >> num2;
                // Verifica se o segundo número é zero antes de dividir
                if (num2 == 0) {
                    cout << "Erro: Divisão por zero não é permitida!" << endl;
                    break;  // Sai do switch
                }
                cout << "Resultado: " << (num1 / num2) << endl;
                break;  // Sai do switch

            case 5:
                cout << "Saindo da calculadora. Até logo!" << endl;
                return 0;  // Sai do programa

            default:
                cout << "Opção inválida! Tente novamente." << endl;
                continue;  // Ignora o resto do loop e volta para o início
        }
    }

    return 0;
}