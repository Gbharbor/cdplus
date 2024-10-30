#include <stdio.h>    // Necessário para operações de entrada e saída
#include <string.h>   // Necessário para manipulação de strings

#define MAX 100      // Define um tamanho máximo para as strings

int main() {
    char str1[MAX] = "Olá";            // Inicializa a primeira string
    char str2[MAX] = " Mundo!";        // Inicializa a segunda string
    char str3[MAX];                    // String para armazenar o resultado da concatenação
    int comprimento;                   // Variável para armazenar o comprimento da string

    // 1. Concatenar strings
    strcpy(str3, str1);                // Copia str1 para str3
    strcat(str3, str2);                // Concatena str2 ao final de str3
    printf("Concatenado: %s\n", str3); // Saída: Olá Mundo!

    // 2. Copiar strings
    char str4[MAX];                    // Outra string para demonstrar cópia
    strcpy(str4, str1);                // Copia str1 para str4
    printf("Cópia: %s\n", str4);       // Saída: Olá

    // 3. Comparar strings
    int resultadoComparacao = strcmp(str1, "Olá"); // Compara str1 com "Olá"
    printf("Resultado da comparação (str1 e 'Olá'): %d\n", resultadoComparacao); // Saída: 0 (iguais)

    // 4. Calcular o comprimento da string
    comprimento = strlen(str1);        // Calcula o comprimento de str1
    printf("Comprimento de str1: %d\n", comprimento); // Saída: 3

    // 5. Encontrar o primeiro caractere 'o' em str3
    char *pos = strchr(str3, 'o');     // Encontra o primeiro 'o' em str3
    if (pos != NULL) {
        printf("Primeira ocorrência de 'o': %s\n", pos); // Saída: o Mundo!
    } else {
        printf("'o' não encontrado.\n");
    }

    return 0; // Indica que o programa terminou corretamente
}
