#include <stdio.h>

int main() {
    int idade;

    // Solicita ao usuário que insira sua idade
    printf("Por favor, insira sua idade: ");
    scanf("%d", &idade);

    // Estrutura condicional if
    if (idade < 0) {
        printf("Idade inválida!\n");
    } 
    // Estrutura condicional if-else
    else if (idade < 18) {
        printf("Você é menor de idade.\n");
    } 
    // Estrutura else
    else {
        printf("Você é maior de idade.\n");
    }

    // Exemplo de uso de else if para categorizar idades
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