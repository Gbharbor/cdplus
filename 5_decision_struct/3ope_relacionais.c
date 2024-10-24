//Operadores Relacionais
#include <stdio.h>

int main() {
    int x = 10, y = 20;

    // Igual a (==)
    printf("x == y: %d\n", x == y);  // Falso (0)

    // Diferente de (!=)
    printf("x != y: %d\n", x != y);  // Verdadeiro (1)

    // Maior que (>)
    printf("x > y: %d\n", x > y);    // Falso (0)

    // Menor que (<)
    printf("x < y: %d\n", x < y);    // Verdadeiro (1)

    // Maior ou igual a (>=)
    printf("x >= y: %d\n", x >= y);  // Falso (0)

    // Menor ou igual a (<=)
    printf("x <= y: %d\n", x <= y);  // Verdadeiro (1)

    return 0;
};