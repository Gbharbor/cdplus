#include <stdio.h>

int main() {
    // Seção de Operadores Aritméticos
    int x = 10, y = 3;
    int result;

    // Operacoes basicas +
    result = x + y; // -, *, /
    printf("Adição: %d + %d = %d\n", x, y, result);

    // Resto da divisão inteira %
    result = x % y;
    printf("Resto da divisão inteira: %d %% %d = %d\n", x, y, result);

    //Incremento vs decremento
    printf("x antes do incremento: %d, após: %d\n", x, ++x);
    printf("y antes do decremento: %d, após: %d\n", y, --y);

    // Operadores Lógicos
    printf("\nOperadores Lógicos:\n");
    printf("(x > 5) && (y < 30): %d\n", (x > 5) && (y < 30));
    printf("(x < 5) || (y > 15): %d\n", (x < 5) || (y > 15));
    printf("!(x == 10): %d\n", !(x == 10));

    // Operadores Relacionais
    printf("\nOperadores Relacionais:\n");
    printf("x == y: %d\n", x == y);
    printf("x != y: %d\n", x != y);
    printf("x > y: %d\n", x > y);
    printf("x < y: %d\n", x < y);
    printf("x >= y: %d\n", x >= y);
    printf("x <= y: %d\n", x <= y);

    // Expressões Simples e Compostas
    printf("\nExpressões:\n");
    if (x < y) {
        printf("x é menor que y\n");
    }
    if ((x > 5) && (y < 30)) {
        printf("x é maior que 5 E y é menor que 30\n");
    }

     // Seção de Verificação de Idade IF/ELSE IF/ ELSE
    int idade;
    printf("\nVerificação de Idade:\n");
    printf("Por favor, insira sua idade: ");
    scanf("%d", &idade);

    if (idade < 0) {
        printf("Idade inválida!\n");
    } else if (idade < 18) {
        printf("Você é menor de idade.\n");
    } else {
        printf("Você é maior de idade.\n");
    }

    printf("\nClassificação de Idade:\n");
    if (idade < 13) {
        printf("Você é uma criança.\n");
    } else if (idade < 20) {
        printf("Você é um adolescente.\n");
    } else if (idade < 65) {
        printf("Você é um adulto.\n");
    } else {
        printf("Você é um idoso.\n");
    }

    return 0; // Finaliza o programa
}