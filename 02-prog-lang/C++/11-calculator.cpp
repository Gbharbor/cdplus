#include <iostream>
using namespace std;

int main() {
    // ======================================================
    // EXEMPLO PRATICO:
    // CALCULADORA SIMPLES COM MENU INTERATIVO
    // ======================================================

    int escolha;       // armazena a opcao escolhida pelo utilizador
    double num1, num2; // numeros usados nas operacoes

    cout << "Bem-vindo a Calculadora Simples!" << endl;

    // Loop infinito para manter o menu ativo
    // O programa so termina quando o utilizador escolher sair
    while (true) {
        cout << "\nEscolha uma operacao:" << endl;
        cout << "1. Adicao" << endl;
        cout << "2. Subtracao" << endl;
        cout << "3. Multiplicacao" << endl;
        cout << "4. Divisao" << endl;
        cout << "5. Sair" << endl;
        cout << "Digite sua escolha (1 a 5): ";
        cin >> escolha;

        // O switch analisa o valor digitado e executa
        // a operacao correspondente
        switch (escolha) {

            case 1:
                cout << "Digite dois numeros para a adicao: ";
                cin >> num1 >> num2;
                cout << "Resultado: " << (num1 + num2) << endl;
                break; // encerra este case e volta ao menu

            case 2:
                cout << "Digite dois numeros para a subtracao: ";
                cin >> num1 >> num2;
                cout << "Resultado: " << (num1 - num2) << endl;
                break; // encerra este case e volta ao menu

            case 3:
                cout << "Digite dois numeros para a multiplicacao: ";
                cin >> num1 >> num2;
                cout << "Resultado: " << (num1 * num2) << endl;
                break; // encerra este case e volta ao menu

            case 4:
                cout << "Digite dois numeros para a divisao: ";
                cin >> num1 >> num2;

                // Antes de dividir, e importante verificar
                // se o denominador e zero
                if (num2 == 0) {
                    cout << "Erro: divisao por zero nao e permitida!" << endl;
                    break; // sai do case e volta ao menu
                }

                cout << "Resultado: " << (num1 / num2) << endl;
                break; // encerra este case e volta ao menu

            case 5:
                cout << "Saindo da calculadora. Ate logo!" << endl;
                return 0; // encerra completamente o programa

            default:
                cout << "Opcao invalida! Tente novamente." << endl;

                // O continue faz o loop voltar imediatamente
                // para o inicio, exibindo novamente o menu
                continue;
        }
    }

    return 0;
}                                         