#include <stdio.h>

/*
    Aula 04 - Vetores (Arrays) em C
    Leitura de valores, índices e cálculo de média
*/

/* =========================================================
   Tópico 1 - Leitura de números inteiros em um vetor
   ========================================================= */
void lerNumerosInteiros() {

    int numeros[3]; // vetor com 3 posições

    printf("=== Leitura de números inteiros ===\n");

    /* leitura dos valores */
    for (int i = 0; i < 3; i++) {

        printf("Digite o número %d: ", i + 1);
        scanf("%d", &numeros[i]);

    }

    /* exibição dos valores */
    printf("\nValores e índices do vetor:\n");

    for (int i = 0; i < 3; i++) {

        printf("Índice %d -> Valor: %d\n", i, numeros[i]);

    }

    printf("\n");
}

/* =========================================================
   Tópico 2 - Cálculo de média usando vetor
   ========================================================= */
void calcularMedia() {

    float notas[3];  // duas notas + posição para média

    printf("=== Cálculo de média ===\n");

    printf("Digite a primeira nota: ");
    scanf("%f", &notas[0]);

    printf("Digite a segunda nota: ");
    scanf("%f", &notas[1]);

    /* cálculo da média */
    notas[2] = (notas[0] + notas[1]) / 2;

    printf("A média das notas %.2f e %.2f é: %.2f\n",
           notas[0], notas[1], notas[2]);

    printf("\n");
}

/* =========================================================
   Função principal
   ========================================================= */
int main() {

    lerNumerosInteiros();
    calcularMedia();

    return 0;
}

/*
Exemplo de execução

Digite o número 1: 5
Digite o número 2: 10
Digite o número 3: 15

Valores e índices do vetor:
Índice 0 -> Valor: 5
Índice 1 -> Valor: 10
Índice 2 -> Valor: 15

Digite a primeira nota: 8.5
Digite a segunda nota: 7.0
A média das notas 8.50 e 7.00 é: 7.75
*/