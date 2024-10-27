///DO WHILE 
/* Estrutura de repetição que garante que um bloco de código seja executado pelo menos uma vez, mesmo que a condição especificada seja falsa. A estrutura básica do `do while` é a seguinte:

do {
    // Código a ser repetido
} while (condição);
 Como Funciona:

- O loop `do while` é útil quando é necessário garantir que o bloco de código seja executado pelo menos uma vez antes de verificar a condição.
- Ele é frequentemente usado em situações onde a entrada do usuário é solicitada e a execução deve ocorrer antes de validar a condição.

1. **Execução do Código**: O bloco de código dentro do `do` é executado primeiro.
2. **Avaliação da Condição**: Após a execução, a condição é avaliada. Se a condição for verdadeira (`true`), o loop se repetirá. Se for falsa (`false`), o loop termina.
3. **Garantia de Execução**: Como a condição é verificada após a execução do bloco, o código dentro do `do` sempre será executado pelo menos uma vez.
*/
//Exemplo Prático :
//Aqui está um exemplo simples que usa um loop `do while` para contar de 1 a 5:

#include <iostream>
using namespace std;

int main() {
    int i = 1;  // Inicializa a variável de controle

    cout << "Contando de 1 a 5 usando do while:" << endl;

    // O loop do while continuará enquanto i for menor ou igual a 5
    do {
        cout << "i = " << i << endl;  // Imprime o valor atual de i
        i++;  // Incrementa i em 1
    } while (i <= 5);

    return 0;
}
/*
Contando de 1 a 5 usando do while:
i = 1
i = 2
i = 3
i = 4
i = 5
*/

//EXEMPLO 2 : SOLICITAR ENTRADA DE USUARIO
#include <iostream>
using namespace std;

int main() {
    int numero;

    do {
        cout << "Digite um número positivo: ";
        cin >> numero;  // Lê um número do usuário
    } while (numero <= 0);  // Continua solicitando até que o número seja positivo

    cout << "Você digitou: " << numero << endl;  // Exibe o número positivo digitado

    return 0;
}
/*
Digite um número positivo: -5
Digite um número positivo: 0
Digite um número positivo: 10
Você digitou: 10
*/

//EXEMPLO 3 : MENU DE OPCOES (Esse exemplo envolve switch q vou estudar em seguida.)
#include <iostream>
using namespace std;

int main() {
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

    return 0;
}
/*
Menu de Opções:
1. Opção 1
2. Opção 2
3. Sair
Escolha uma opção: 1
Você escolheu a Opção 1.
Menu de Opções:
1. Opção 1
2. Opção 2
3. Sair
Escolha uma opção: 3
Saindo do menu...
*/

//EXEMPLO 4 : TABUADA
#include <iostream>
using namespace std;

int main() {
    int numero, i = 1;

    cout << "Digite um número para ver sua tabuada: ";
    cin >> numero;  // Lê o número do usuário

    do {
        cout << numero << " x " << i << " = " << numero * i << endl;  // Exibe a multiplicação
        i++;  // Incrementa i em 1
    } while (i <= 10);  // Continua até i ser maior que 10

    return 0;
}
/*
Digite um número para ver sua tabuada: 3
3 x 1 = 3
3 x 2 = 6
3 x 3 = 9
3 x 4 = 12
3 x 5 = 15
3 x 6 = 18
3 x 7 = 21
3 x 8 = 24
3 x 9 = 27
3 x 10 = 30
*/