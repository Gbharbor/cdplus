#include <iostream>
using namespace std;

// Função principal
int main() {
    // Seção 1: Uso do break dentro de um loop for
    cout << "Uso do break dentro de um loop for:\n";
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break;  // Interrompe o loop quando i é 5
        }
        cout << "i = " << i << endl;  // Imprime o valor de i
    }
    cout << "Loop interrompido." << endl;
    cout << endl;  // Para separar a saída

    // Seção 2: Uso do break em um loop aninhado
    cout << "Uso do break em um loop aninhado:\n";
    for (int i = 0; i < 3; i++) {  // Loop externo
        for (int j = 0; j < 3; j++) {  // Loop interno
            if (j == 1) {
                break;  // Interrompe apenas o loop interno
            }
            cout << "i = " << i << ", j = " << j << endl;  // Imprime valores de i e j
        }
    }
    cout << endl;  // Para separar a saída

    return 0;  // Finaliza o programa
}

/*
Uso do break dentro de um loop for:
i = 0
i = 1
i = 2
i = 3
i = 4
Loop interrompido.
*/
/*
Uso do break em um loop aninhado:
i = 0, j = 0
i = 1, j = 0
i = 2, j = 0
*/