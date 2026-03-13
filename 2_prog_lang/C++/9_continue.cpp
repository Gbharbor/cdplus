#include <iostream>
using namespace std;

int main() {

    // ======================================================
    // EXEMPLO 1 - CONTINUE EM LOOP FOR
    // ======================================================
    cout << "EXEMPLO 1: Uso do continue dentro de um loop for\n";

    for (int i = 0; i < 10; i++) {

        if (i % 2 == 0) {
            continue; // pula os numeros pares
        }

        cout << "i = " << i << endl; // imprime apenas numeros impares
    }

    cout << endl;


    // ======================================================
    // EXEMPLO 2 - CONTINUE EM LOOPS ANINHADOS
    // ======================================================
    cout << "EXEMPLO 2: Uso do continue em loops aninhados\n";

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (j == 1) {
                continue; // pula apenas quando j == 1
            }

            cout << "i = " << i << ", j = " << j << endl;
        }
    }

    cout << endl;


    // ======================================================
    // EXEMPLO 3 - PULAR UMA ITERACAO ESPECIFICA
    // ======================================================
    cout << "EXEMPLO 3: Pular uma iteracao especifica\n";

    for (int i = 0; i < 5; i++) {

        if (i == 2) {
            continue; // pula quando i == 2
        }

        cout << "i = " << i << endl;
    }

    cout << endl;

    return 0;
}
/*
Uso do continue dentro de um loop for:
i = 1
i = 3
i = 5
i = 7
i = 9
*/
/*
Uso do continue em loops aninhados:
i = 0, j = 0
i = 0, j = 2
i = 1, j = 0
i = 1, j = 2
i = 2, j = 0
i = 2, j = 2
*/
/*
Uso do continue no laço for:
i = 0
i = 1
i = 3
i = 4
*/