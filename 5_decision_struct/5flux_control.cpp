
//Estrutura de Controle de fluxo
#include <iostream>
using namespace std;

int main() {
    int x = 10, y = 20;

    // --- Estruturas de Controle Condicional ---

    // 1. Condicional if-else
    cout << "Condicional if-else:\n";
    if (x > y) {
        cout << "x é maior que y" << endl;
    } else if (x == y) {
        cout << "x é igual a y" << endl;
    } else {
        cout << "x é menor que y" << endl;
    }
    cout << endl; // Para separar a saída

    // 2. Estrutura switch
    cout << "Estrutura switch:\n";
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

    // --- Estruturas de Controle de Repetição (Laços) ---

    // 3. Laço for
    cout << "Laço for:\n";
    for (int i = 0; i < 5; i++) { // i começa em 0 e vai até 4
        cout << "i = " << i << endl; // Exibe o valor de i
    }
    cout << endl; // Para separar a saída

    // 4. Laço while
    cout << "Laço while:\n";
    int i = 0; // Inicializa i
    while (i < 5) { // Enquanto i for menor que 5
        cout << "i = " << i << endl; // Exibe o valor de i
        i++; // Incrementa i em 1
    }
    cout << endl; // Para separar a saída

    // 5. Laço do-while
    cout << "Laço do-while:\n";
    i = 0; // Inicializa i novamente
    do {
        cout << "i = " << i << endl; // Exibe o valor de i
        i++; // Incrementa i em 1
    } while (i < 5); // Enquanto i for menor que 5
    cout << endl; // Para separar a saída

    // --- Desvios Incondicionais ---

    // 6. Uso do break
    cout << "Uso do break no laço for:\n";
    for (i = 0; i < 10; i++) { // Laço que vai de 0 a 9
        if (i == 5) { // Se i for igual a 5
            break; // Sai do laço
        }
        cout << "i = " << i << endl; // Exibe o valor de i
    }
    cout << endl; // Para separar a saída

    // 7. Uso do continue
    cout << "Uso do continue no laço for:\n";
    for (i = 0; i < 5; i++) { // Laço que vai de 0 a 4
        if (i == 2) { // Se i for igual a 2
            continue; // Pula a iteração atual
        }
        cout << "i = " << i << endl; // Exibe o valor de i
    }
    cout << endl; // Para separar a saída

    // 8. Uso do goto
    cout << "Uso do goto:\n";
    if (x == 10) { // Se x for igual a 10
        goto etiqueta; // Salta para a etiqueta "etiqueta"
    }
    cout << "Este código será ignorado." << endl;

etiqueta: // Etiqueta para onde o programa pode saltar
    cout << "Salto realizado com goto!" << endl;

    return 0; // Finaliza o programa
}