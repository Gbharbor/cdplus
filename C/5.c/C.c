#include <stdio.h>

int main() {
    // Seção de Operadores Aritméticos
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

    // Seção de Operadores Lógicos
    int resultado;

    // Operador Lógico AND (&&)
    resultado = (x > 5) && (y < 30);
    printf("Resultado de (x > 5) && (y < 30): %d\n", resultado); // Esperado: 1 (verdadeiro)

    // Operador Lógico OR (||)
    resultado = (x < 5) || (y > 15);
    printf("Resultado de (x < 5) || (y > 15): %d\n", resultado); // Esperado: 1 (verdadeiro)

    // Operador Lógico NOT (!)
    resultado = !(x == 10);
    printf("Resultado de !(x == 10): %d\n", resultado); // Esperado: 0 (falso)

    // Seção de Operadores Relacionais
    printf("\nOperadores Relacionais:\n");
    printf("x == y: %d\n", x == y);  // Falso (0)
    printf("x != y: %d\n", x != y);  // Verdadeiro (1)
    printf("x > y: %d\n", x > y);    // Falso (0)
    printf("x < y: %d\n", x < y);    // Verdadeiro (1)
    printf("x >= y: %d\n", x >= y);  // Falso (0)
    printf("x <= y: %d\n", x <= y);  // Verdadeiro (1)

    // Seção de Expressões Simples e Compostas
    printf("\nExpressões:\n");
    // Expressão simples
    if (x < y) {
        printf("x é menor que y\n");  // Apenas uma condição é avaliada
    }

    // Expressão composta
    if ((x > 5) && (y < 30)) {
        printf("x é maior que 5 E y é menor que 30\n");  // Ambas as condições precisam ser verdadeiras
    }

    return 0;
}