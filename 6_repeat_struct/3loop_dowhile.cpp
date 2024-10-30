#include <iostream>
using namespace std;

// Função para pausar o console, útil em sistemas Windows
void pause() {
    system("PAUSE > nul");
}

// Função principal
int main() {
    // --- EXEMPLO 1: Contagem de 1 a 5 ---
    cout << "EXEMPLO 1: Contando de 1 a 5 usando do while:" << endl;
    int i = 1;  // Inicializa a variável de controle

    // O loop do while continuará enquanto i for menor ou igual a 5
    do {
        cout << "i = " << i << endl;  // Imprime o valor atual de i
        i++;  // Incrementa i em 1
    } while (i <= 5);

    cout << endl; // Linha em branco para separar os exemplos

    // --- EXEMPLO 2: Solicitar Entrada do Usuário ---
    cout << "EXEMPLO 2: Solicitar um número positivo" << endl;
    int numero;

    do {
        cout << "Digite um número positivo: ";
        cin >> numero;  // Lê um número do usuário
    } while (numero <= 0);  // Continua solicitando até que o número seja positivo

    cout << "Você digitou: " << numero << endl;  // Exibe o número positivo digitado
    cout << endl; // Para separar a saída

    // --- EXEMPLO 3: Menu de Opções ---
    cout << "EXEMPLO 3: Menu de Opções" << endl;
    int opcao;

    do {
        cout << "Menu de Opções:" << endl;
        cout << "1. Opção 1" << endl;
        cout << "2. Opção 2" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;  // Lê a opção do usuário

        switch (opcao) {
            case 1:
                cout << "Você escolheu a Opção 1." << endl;
                break;
            case 2:
                cout << "Você escolheu a Opção 2." << endl;
                break;
            case 3:
                cout << "Saindo do menu..." << endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (opcao != 3);  // Continua até que o usuário escolha sair

    cout << endl; // Para separar a saída

    // --- EXEMPLO 4: Tabuada ---
    cout << "EXEMPLO 4: Tabuada" << endl;
    int numeroTabuada, j = 1;

    cout << "Digite um número para ver sua tabuada: ";
    cin >> numeroTabuada;  // Lê o número do usuário

    do {
        cout << numeroTabuada << " x " << j << " = " << numeroTabuada * j << endl;  // Exibe a multiplicação
        j++;  // Incrementa j em 1
    } while (j <= 10);  // Continua até j ser maior que 10

    cout << endl; // Para separar a saída

    // --- EXEMPLO 5: Laço do-while Simples ---
    cout << "EXEMPLO 5: Laço do-while simples" << endl;
    i = 0; // Inicializa i novamente
    do {
        cout << "i = " << i << endl; // Exibe o valor de i
        i++; // Incrementa i em 1
    } while (i < 5); // Enquanto i for menor que 5
    cout << endl; // Para separar a saída

    return 0; // Retorna 0 para indicar que o programa terminou sem erros
}