/* CONTINUE
O comando continue é usado para pular a iteração atual de um loop e passar para a próxima iteração. Quando um continue é encontrado, as instruções restantes na iteração atual são ignoradas, e o controle volta ao início do loop.

continue: Usado dentro de loops para pular a iteração atual e passar para a próxima iteração. As instruções restantes na iteração atual são ignoradas.
*/
//EXEMPLO 1 : USANDO CONTINUE NO FOR
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue;  // Pula os números pares
        }
        cout << "i = " << i << endl;  // Imprime o valor de i se for ímpar
    }

    return 0;
}
/*
i = 1
i = 3
i = 5
i = 7
i = 9
*/

//EXEMPLO 2 : CONTINUA EM LACOS ANINHADOS
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {  // Loop externo
        for (int j = 0; j < 3; j++) {  // Loop interno
            if (j == 1) {
                continue;  // Pula apenas o número 1 e continua a iteração
            }
            cout << "i = " << i << ", j = " << j << endl;
        }
    }
    return 0;
}
/*
i = 0, j = 0
i = 0, j = 2
i = 1, j = 0
i = 1, j = 2
i = 2, j = 0
i = 2, j = 2
*/