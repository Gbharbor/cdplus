#include <stdio.h>

// Função para ler números inteiros e exibir seus índices
void lerNumerosInteiros() {
    int numeros[3]; // Vetor para armazenar 3 números inteiros

    // Lê os elementos do vetor a partir da entrada do usuário
    for (int i = 0; i < 3; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Exibe os elementos armazenados no vetor juntamente com seus índices
    printf("\nValores e índices do vetor:\n");
    for (int i = 0; i < 3; i++) {
        printf("Índice %d -> Valor: %d\n", i, numeros[i]);
    }
}

// Função para calcular a média de duas notas
void calcularMedia() {
    float notas[3];  // Vetor para armazenar duas notas e a média

    // Solicita as duas notas ao usuário
    printf("\nDigite a primeira nota: ");
    scanf("%f", &notas[0]);

    printf("Digite a segunda nota: ");
    scanf("%f", &notas[1]);

    // Calcula a média e armazena na terceira posição do vetor
    notas[2] = (notas[0] + notas[1]) / 2;

    // Exibe a média
    printf("A média das notas %.2f e %.2f é: %.2f\n", notas[0], notas[1], notas[2]);
}

int main() {
    // Chama a função para ler números inteiros
    lerNumerosInteiros();

    // Chama a função para calcular a média
    calcularMedia();

    return 0; // Finaliza o programa
}

/*
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