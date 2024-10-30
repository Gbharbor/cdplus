#include <iostream>
using namespace std;

// Função principal
int main() {
    // Seção 1: Uso do continue dentro de um loop for
    cout << "Uso do continue dentro de um loop for:\n";
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue;  // Pula os números pares
        }
        cout << "i = " << i << endl;  // Imprime o valor de i se for ímpar
    }
    cout << endl;  // Para separar a saída

    // Seção 2: Uso do continue em loops aninhados
    cout << "Uso do continue em loops aninhados:\n";
    for (int i = 0; i < 3; i++) {  // Loop externo
        for (int j = 0; j < 3; j++) {  // Loop interno
            if (j == 1) {
                continue;  // Pula apenas o número 1 e continua a iteração
            }
            cout << "i = " << i << ", j = " << j << endl;  // Imprime valores de i e j
        }
    }
    cout << endl;  // Para separar a saída

    // Seção 3: Outro exemplo de uso do continue
    cout << "Uso do continue no laço for:\n";
    for (int i = 0; i < 5; i++) {  // Laço que vai de 0 a 4
        if (i == 2) {  // Se i for igual a 2
            continue;  // Pula a iteração atual
        }
        cout << "i = " << i << endl;  // Exibe o valor de i
    }
    cout << endl;  // Para separar a saída

    return 0;  // Finaliza o programa
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