// ------------------------------------------------------------
// 2. Ponteiros em Funções: Passagem por Referência
// ------------------------------------------------------------

/*
Podemos criar funções que recebem parâmetros de duas formas:

1) Por valor (pass-by-value)
   A função recebe uma cópia do valor da variável.
   Alterações dentro da função NÃO modificam a variável original.

2) Por referência (pass-by-reference)
   A função recebe o endereço da variável.
   Assim, ela pode alterar diretamente o valor original.

Neste exemplo usamos ponteiros para realizar passagem por referência.
*/

// Lembrete importante:
// ponteiro = endereço da variável
// *ponteiro = valor armazenado naquele endereço

#include <iostream>
using namespace std;


// ------------------------------------------------------------
// Função que calcula potência alterando o valor original
// ------------------------------------------------------------

void power(int *number, int exponent) {

    int originalValue = *number; // guarda o valor original

    // Qualquer número elevado a 0 é 1
    if (exponent == 0) {
        *number = 1;
        return;
    }

    // Multiplica o valor original por ele mesmo (exponent - 1) vezes
    for (int i = 2; i <= exponent; i++) {
        *number = (*number) * originalValue;
    }
}

int main() {

    int value = 9;

    // Passamos o endereço da variável usando &
    power(&value, 0);

    cout << "Resultado da potência: " << value << endl;

    return 0;
}