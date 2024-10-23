#include <stdio.h>

/*
 * Resumo dos tipos de variáveis e seus especificadores:
 * - Inteiro: %d ou %i
 * - Caractere: %c
 * - String (texto): %s
 * - Ponto flutuante: %f (use %.2f para 2 casas decimais)
 * - Double: %lf
 * - Inteiro longo: %ld
 * - Unsigned inteiro: %u
 * - Hexadecimal: %x ou %X
 * - Notação científica: %e ou %E
 * - Formato automático: %g ou %G
 */

// Função para imprimir os tipos de variáveis
void imprimirVariaveis() {
    // Variáveis para os exemplos
    int numero = 42;                    // Inteiro
    char letra = 'A';                   // Caractere
    char nome[] = "Alice";              // String
    float pi = 3.14159;                 // Float
    double grande_numero = 1234567.89;  // Double
    long int numero_grande = 1234567890; // Long Inteiro
    unsigned int numero_unsigned = 40000; // Unsigned Inteiro
    float num1 = 0.000123456;           // Exemplo de notação científica
    float num2 = 123456780;              // Outro exemplo
    float num3 = 3.14159265358979323846; // Pi com alta precisão

    // Exemplos de printf com diferentes especificadores
    printf("1. O valor do número inteiro é: %d\n", numero); // %d
    printf("2. A letra é: %c\n", letra);                     // %c
    printf("3. O nome é: %s\n", nome);                       // %s
    printf("4. O valor de pi é: %f\n", pi);                  // %f
    printf("5. O valor de grande_numero é: %lf\n", grande_numero); // %lf
    printf("6. O valor do número grande é: %ld\n", numero_grande); // %ld
    printf("7. O valor do número unsigned é: %u\n", numero_unsigned); // %u
    printf("8. O valor em hexadecimal é: %x\n", numero);    // %x
    printf("9. O valor em hexadecimal (maiúsculas) é: %X\n", numero); // %X
    printf("10. O valor em notação científica é: %e\n", pi); // %e
    printf("11. O valor em notação científica (maiúsculas) é: %E\n", pi); // %E

    // Exemplo com precisão
    printf("12. A altura é: %.2f metros\n", 1.75); // %.2f

    // Usando %g com precisão
    printf("Usando %%g:\n");
    printf("num1: %.8g\n", num1); // Exibição em notação científica ou normal
    printf("num2: %.8g\n", num2); // O ponto decimal aparecerá
    printf("num3: %.8g\n", num3); // Exibição em notação normal ou científica

    // Usando %G com precisão
    printf("\nUsando %%G:\n");
    printf("Num1: %.8G\n", num1); // Exibição em notação normal ou científica
    printf("Num2: %.8G\n", num2); // O ponto decimal aparecerá
    printf("Num3: %.8G\n", num3); // Exibição em notação normal ou científica
}

int main() {
    imprimirVariaveis(); // Chama a função para imprimir as variáveis
    return 0;
}