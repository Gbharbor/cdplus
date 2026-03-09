#include <stdio.h>   // Necessário para funções de entrada e saída
#include <string.h>  // Necessário para manipulação de strings

int main() {
    // Declarando e inicializando uma string em C
    char str1[20] = "Olá, mundo!";  // Declara uma string com 20 caracteres, inicializada com "Olá, mundo!"

    // Outra forma de inicialização (sem especificar o tamanho)
    char str2[] = "Olá, C!";         // O compilador determina o tamanho automaticamente

    printf("String 1: %s\n", str1);  // Imprime a primeira string
    printf("String 2: %s\n", str2);  // Imprime a segunda string

    return 0; // Indica que o programa terminou corretamente
}
