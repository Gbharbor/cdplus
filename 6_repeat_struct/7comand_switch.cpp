#include <iostream>
using namespace std;

// Função principal
int main() {
    // Seção 1: Exemplo de switch para determinar o dia da semana
    int dia;

    cout << "Digite um número de 1 a 7 para o dia da semana: ";
    cin >> dia;  // Lê o dia da semana

    switch (dia) {
        case 1:
            cout << "Domingo" << endl;
            break;
        case 2:
            cout << "Segunda-feira" << endl;
            break;
        case 3:
            cout << "Terça-feira" << endl;
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
            cout << "Sábado" << endl;
            break;
        default:
            cout << "Número inválido! Digite um número de 1 a 7." << endl;
    }
    cout << endl;  // Para separar a saída

    // Seção 2: Uso do switch em loops aninhados
    for (int i = 0; i < 2; i++) {  // Loop externo
        int escolha;
        cout << "Escolha (1 ou 2): ";
        cin >> escolha;  // Lê a escolha do usuário

        switch (escolha) {  // Estrutura switch
            case 1:
                cout << "Você escolheu a opção 1." << endl;
                break;
            case 2:
                cout << "Você escolheu a opção 2." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
        cout << endl;  // Para separar a saída de cada iteração
    }

    // Seção 3: Outro exemplo de estrutura switch
    int x;
    cout << "Digite um valor para x (10 ou 20): ";
    cin >> x;  // Lê o valor de x

    switch (x) {
        case 10:
            cout << "x é igual a 10" << endl;
            break; // Sai do switch
        case 20:
            cout << "x é igual a 20" << endl;
            break; // Sai do switch
        default:
            cout << "x não é 10 nem 20" << endl;
            break; // Sai do switch
    }
    cout << endl; // Para separar a saída

    return 0;  // Finaliza o programa
}