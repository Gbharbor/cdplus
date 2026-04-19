#include <iostream>
using namespace std;

int main() {

    // ======================================================
    // EXEMPLO 1 - USO DO BREAK EM UM LOOP FOR
    // ======================================================
    cout << "EXEMPLO 1: Uso do break dentro de um loop for\n";

    for (int i = 0; i < 10; i++) {

        if (i == 5) {
            break; // interrompe o loop quando i for igual a 5
        }

        cout << "i = " << i << endl;
    }

    cout << "Loop interrompido." << endl;
    cout << endl;


    // ======================================================
    // EXEMPLO 2 - BREAK EM LOOP ANINHADO
    // ======================================================
    cout << "EXEMPLO 2: Uso do break em loops aninhados\n";

    for (int i = 0; i < 3; i++) { // loop externo

        for (int j = 0; j < 3; j++) { // loop interno

            if (j == 1) {
                break; // interrompe apenas o loop interno
            }

            cout << "i = " << i << ", j = " << j << endl;
        }
    }

    cout << endl;

    return 0;
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