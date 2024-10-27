/*
SWITCH :  nao é um laço ! 
A estrutura switch é uma forma de selecionar entre múltiplas opções, dependendo do valor de uma expressão. Em vez de usar várias instruções if para testar uma única variável, você pode usar um switch para tornar o código mais claro e eficiente.

switch: Usado para selecionar entre múltiplas opções de forma mais clara e eficiente. É uma alternativa a múltiplas instruções if quando você está verificando o valor de uma única variável contra vários casos.

switch (expressão) {
    case valor1:
        // Instruções para valor1
        break;
    case valor2:
        // Instruções para valor2
        break;
    // ...
    default:
        // Instruções se nenhum case for atendido
}
case: Define um valor que a expressão pode ter.
break: Interrompe a execução após a execução do código para o caso correspondente. Se break não for usado, a execução continuará nos próximos casos (isso é chamado de "fall-through").
default: Opcional, é executado se nenhum dos valores especificados em case for atendido.

*/
//EXEMPLO 1 :  dia da semana com base em um número:
#include <iostream>
using namespace std;

int main() {
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

    return 0;
}
/*
Digite um número de 1 a 7 para o dia da semana: 3
Terça-feira
*/
//EXEMPLO 2 : SWITCH EM LACOS ANINHADOS
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 2; i++) {  // Loop externo
        int escolha;
        cout << "Escolha (1 ou 2): ";
        cin >> escolha;

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
    }
    return 0;
}
/*
Escolha (1 ou 2): 1
Você escolheu a opção 1.
Escolha (1 ou 2): 3
Opção inválida.
*/