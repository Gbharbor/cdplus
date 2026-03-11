#include <stdio.h>

/*
    Aula de C - Operadores e Estruturas Condicionais
    Organização por tópicos para estudo
*/

/* =========================================================
   Tópico 1 - Operadores aritméticos
   ========================================================= */
void operadoresAritmeticos(void) {

    int x = 10;
    int y = 3;
    int result;

    printf("=== Tópico 1 - Operadores Aritméticos ===\n");

    /* Operações básicas */
    result = x + y;
    printf("Adição: %d + %d = %d\n", x, y, result);

    result = x - y;
    printf("Subtração: %d - %d = %d\n", x, y, result);

    result = x * y;
    printf("Multiplicação: %d * %d = %d\n", x, y, result);

    result = x / y;
    printf("Divisão inteira: %d / %d = %d\n", x, y, result);

    /* Resto da divisão */
    result = x % y;
    printf("Resto da divisão inteira: %d %% %d = %d\n", x, y, result);

    printf("\n");
}

/* =========================================================
   Tópico 2 - Operadores de incremento e decremento
   ========================================================= */
void incrementoDecremento(void) {

    int x = 10;
    int y = 3;

    printf("=== Tópico 2 - Incremento e Decremento ===\n");

    printf("Valor inicial de x: %d\n", x);
    x++;
    printf("Após incremento (x++): %d\n", x);

    printf("Valor inicial de y: %d\n", y);
    y--;
    printf("Após decremento (y--): %d\n", y);

    printf("\n");
}

/* =========================================================
   Tópico 3 - Operadores lógicos
   ========================================================= */
void operadoresLogicos(void) {

    int x = 10;
    int y = 3;

    printf("=== Tópico 3 - Operadores Lógicos ===\n");

    printf("(x > 5) && (y < 30) = %d\n", (x > 5) && (y < 30));
    printf("(x < 5) || (y > 15) = %d\n", (x < 5) || (y > 15));
    printf("!(x == 10) = %d\n", !(x == 10));

    printf("\n");
}

/* =========================================================
   Tópico 4 - Operadores relacionais
   ========================================================= */
void operadoresRelacionais(void) {

    int x = 10;
    int y = 3;

    printf("=== Tópico 4 - Operadores Relacionais ===\n");

    printf("x == y : %d\n", x == y);
    printf("x != y : %d\n", x != y);
    printf("x > y  : %d\n", x > y);
    printf("x < y  : %d\n", x < y);
    printf("x >= y : %d\n", x >= y);
    printf("x <= y : %d\n", x <= y);

    printf("\n");
}

/* =========================================================
   Tópico 5 - Expressões condicionais simples
   ========================================================= */
void expressoesCondicionais(void) {

    int x = 10;
    int y = 3;

    printf("=== Tópico 5 - Expressões Condicionais ===\n");

    if (x < y) {
        printf("x é menor que y\n");
    }

    if ((x > 5) && (y < 30)) {
        printf("x é maior que 5 e y é menor que 30\n");
    }

    printf("\n");
}

/* =========================================================
   Tópico 6 - Estrutura IF / ELSE IF / ELSE
   ========================================================= */
void verificarIdade(void) {

    int idade;

    printf("=== Tópico 6 - Verificação de Idade ===\n");
    printf("Por favor, insira sua idade: ");
    scanf("%d", &idade);

    if (idade < 0) {
        printf("Idade inválida!\n");
    }
    else if (idade < 18) {
        printf("Você é menor de idade.\n");
    }
    else {
        printf("Você é maior de idade.\n");
    }

    printf("\n");
}

/* =========================================================
   Tópico 7 - Classificação por faixa etária
   ========================================================= */
void classificarIdade(void) {

    int idade;

    printf("=== Tópico 7 - Classificação de Idade ===\n");
    printf("Digite novamente sua idade: ");
    scanf("%d", &idade);

    if (idade < 13) {
        printf("Você é uma criança.\n");
    }
    else if (idade < 20) {
        printf("Você é um adolescente.\n");
    }
    else if (idade < 65) {
        printf("Você é um adulto.\n");
    }
    else {
        printf("Você é um idoso.\n");
    }

    printf("\n");
}

/* =========================================================
   Função principal
   ========================================================= */
int main(void) {

    operadoresAritmeticos();
    incrementoDecremento();
    operadoresLogicos();
    operadoresRelacionais();
    expressoesCondicionais();
    verificarIdade();
    classificarIdade();

    return 0;
}