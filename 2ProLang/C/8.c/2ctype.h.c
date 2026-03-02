#include <stdio.h>
#include <ctype.h> // Inclui a biblioteca ctype.h
//atencao que <cctype> e para c++

int main() {
    char caractere;

    // Solicita ao usuário que digite um caractere
    printf("Digite um caractere: ");
    scanf(" %c", &caractere); // O espaço antes de %c ignora espaços em branco

    // Exemplo de uso das funções da biblioteca <ctype.h>

    // Verificando se o caractere é alfanumérico
    if (isalnum(caractere)) {
        printf("'%c' é um caractere alfanumérico.\n", caractere);
    } else {
        printf("'%c' não é um caractere alfanumérico.\n", caractere);
    }

    // Verificando se o caractere é uma letra
    if (isalpha(caractere)) {
        printf("'%c' é uma letra.\n", caractere);
    } else {
        printf("'%c' não é uma letra.\n", caractere);
    }

    // Verificando se o caractere é um dígito
    if (isdigit(caractere)) {
        printf("'%c' é um dígito.\n", caractere);
    } else {
        printf("'%c' não é um dígito.\n", caractere);
    }

    // Verificando se o caractere é minúsculo ou maiúsculo
    if (islower(caractere)) {
        printf("'%c' é uma letra minúscula.\n", caractere);
        // Convertendo para maiúsculo
        char maiusculo = toupper(caractere);
        printf("Versão maiúscula: '%c'\n", maiusculo);
    } else if (isupper(caractere)) {
        printf("'%c' é uma letra maiúscula.\n", caractere);
        // Convertendo para minúsculo
        char minusculo = tolower(caractere);
        printf("Versão minúscula: '%c'\n", minusculo);
    } else {
        printf("'%c' não é uma letra.\n", caractere);
    }

    // Verificando se o caractere é um espaço em branco
    if (isspace(caractere)) {
        printf("'%c' é um espaço em branco.\n", caractere);
    } else {
        printf("'%c' não é um espaço em branco.\n", caractere);
    }

    return 0; // Indica que o programa terminou corretamente
}