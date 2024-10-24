#include <stdio.h>

int main() {
    int x = 10, y = 3;
    int result;

    // Adição +
    result = x + y;
    printf("Adição: %d + %d = %d\n", x, y, result);

    // Subtração -
    result = x - y;
    printf("Subtração: %d - %d = %d\n", x, y, result);

    // Multiplicação *
    result = x * y;
    printf("Multiplicação: %d * %d = %d\n", x, y, result);

    // Divisão /
    result = x / y;
    printf("Divisão: %d / %d = %d\n", x, y, result);

    // Resto da divisão inteira %
    result = x % y;
    printf("Resto da divisão inteira: %d %% %d = %d\n", x, y, result);

    // Incremento unário ++
    printf("Valor de x antes do incremento: %d\n", x);
    x++;
    printf("Valor de x após o incremento: %d\n", x);

    // Decremento unário --
    printf("Valor de y antes do decremento: %d\n", y);
    y--;
    printf("Valor de y após o decremento: %d\n", y);

    return 0;
};
/*
Adição: 10 + 3 = 13
Subtração: 10 - 3 = 7
Multiplicação: 10 * 3 = 30
Divisão: 10 / 3 = 3
Resto da divisão inteira: 10 % 3 = 1
Valor de x antes do incremento: 10
Valor de x após o incremento: 11
Valor de y antes do decremento: 3
Valor de y após o decremento: 2

*/