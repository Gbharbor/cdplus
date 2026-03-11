#include <stdio.h>
#include <ctype.h>

/*
    Aula 10 - Biblioteca ctype.h

    A biblioteca <ctype.h> fornece funções para testar
    e converter caracteres.

    Observação:
    <ctype.h> é usado em C.
    <cctype> é o equivalente em C++.
*/

/* =========================================================
   Tópico 1 - Verificar se é alfanumérico
   ========================================================= */
void exemploIsalnum(char caractere) {
    printf("=== Tópico 1 - isalnum ===\n");

    if (isalnum((unsigned char)caractere)) {
        printf("'%c' é um caractere alfanumérico.\n", caractere);
    } else {
        printf("'%c' não é um caractere alfanumérico.\n", caractere);
    }

    printf("\n");
}

/* =========================================================
   Tópico 2 - Verificar se é letra
   ========================================================= */
void exemploIsalpha(char caractere) {
    printf("=== Tópico 2 - isalpha ===\n");

    if (isalpha((unsigned char)caractere)) {
        printf("'%c' é uma letra.\n", caractere);
    } else {
        printf("'%c' não é uma letra.\n", caractere);
    }

    printf("\n");
}

/* =========================================================
   Tópico 3 - Verificar se é dígito
   ========================================================= */
void exemploIsdigit(char caractere) {
    printf("=== Tópico 3 - isdigit ===\n");

    if (isdigit((unsigned char)caractere)) {
        printf("'%c' é um dígito.\n", caractere);
    } else {
        printf("'%c' não é um dígito.\n", caractere);
    }

    printf("\n");
}

/* =========================================================
   Tópico 4 - Verificar se é minúsculo ou maiúsculo
   ========================================================= */
void exemploLowerUpper(char caractere) {
    printf("=== Tópico 4 - islower / isupper / tolower / toupper ===\n");

    if (islower((unsigned char)caractere)) {
        char maiusculo = toupper((unsigned char)caractere);
        printf("'%c' é uma letra minúscula.\n", caractere);
        printf("Versão maiúscula: '%c'\n", maiusculo);
    } else if (isupper((unsigned char)caractere)) {
        char minusculo = tolower((unsigned char)caractere);
        printf("'%c' é uma letra maiúscula.\n", caractere);
        printf("Versão minúscula: '%c'\n", minusculo);
    } else {
        printf("'%c' não é uma letra.\n", caractere);
    }

    printf("\n");
}

/* =========================================================
   Tópico 5 - Verificar se é espaço em branco
   ========================================================= */
void exemploIsspace(char caractere) {
    printf("=== Tópico 5 - isspace ===\n");

    if (isspace((unsigned char)caractere)) {
        printf("O caractere informado é um espaço em branco.\n");
    } else {
        printf("'%c' não é um espaço em branco.\n", caractere);
    }

    printf("\n");
}

/* =========================================================
   Tópico 6 - Observações finais
   ========================================================= */
void observacoesCtype(void) {
    printf("=== Tópico 6 - Observações finais ===\n");
    printf("1. isalnum -> verifica se é letra ou número.\n");
    printf("2. isalpha -> verifica se é letra.\n");
    printf("3. isdigit -> verifica se é dígito.\n");
    printf("4. islower -> verifica se é letra minúscula.\n");
    printf("5. isupper -> verifica se é letra maiúscula.\n");
    printf("6. tolower -> converte para minúscula.\n");
    printf("7. toupper -> converte para maiúscula.\n");
    printf("8. isspace -> verifica se é espaço, tab ou quebra de linha.\n");
    printf("\n");
}

/* =========================================================
   Função principal
   ========================================================= */
int main(void) {
    char caractere;

    printf("Digite um caractere: ");
    scanf(" %c", &caractere); /* espaço antes do %c ignora ENTER e espaços */

    printf("\n");

    exemploIsalnum(caractere);
    exemploIsalpha(caractere);
    exemploIsdigit(caractere);
    exemploLowerUpper(caractere);
    exemploIsspace(caractere);
    observacoesCtype();

    return 0;
}