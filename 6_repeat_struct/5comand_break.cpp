//BREAK
/*
O comando break é utilizado para interromper a execução de um loop ou de uma estrutura de controle de seleção (como um switch). Quando um break é encontrado, o controle do programa é transferido para a instrução que se segue ao loop ou ao bloco de seleção.

break: Usado para sair de um loop ou de um switch. Interrompe imediatamente a execução e continua a execução após o bloco do loop ou do switch.
*/
//EXEMPLO 1 : BREAK dentro do FOR
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break;  // Interrompe o loop quando i é 5
        }
        cout << "i = " << i << endl;  // Imprime o valor de i
    }
    
    cout << "Loop interrompido." << endl;

    return 0;
}
/*
i = 0
i = 1
i = 2
i = 3
i = 4
Loop interrompido.

*/

//EXEMPLO 2 : BREAK em um laco ANINHADO
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {  // Loop externo
        for (int j = 0; j < 3; j++) {  // Loop interno
            if (j == 1) {
                break;  // Interrompe apenas o loop interno
            }
            cout << "i = " << i << ", j = " << j << endl;
        }
    }
    return 0;
}
/*
i = 0, j = 0
i = 1, j = 0
i = 2, j = 0
*/