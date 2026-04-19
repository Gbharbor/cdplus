#include <stdio.h>
#include <stdlib.h>

/*
    Aula 12 - Conversão de Strings para Números

    Biblioteca utilizada:
    <stdlib.h>

    Funções abordadas:
    - atoi
    - atof
    - atoll
    - strtol
    - strtod
*/

/* =========================================================
   Tópico 1 - atoi (string -> int)
   ========================================================= */
void exemploAtoi(void) {

    /*
        atoi significa "ASCII to Integer".

        Converte uma string para inteiro.
        Porém não faz verificação de erro robusta.
    */

    const char *cstr = "12345";

    int numero = atoi(cstr);

    printf("=== Tópico 1 - atoi ===\n");
    printf("String: %s\n", cstr);
    printf("Número convertido: %d\n", numero);
    printf("\n");
}


/* =========================================================
   Tópico 2 - atof (string -> double)
   ========================================================= */
void exemploAtof(void) {

    /*
        atof significa "ASCII to Float".

        Converte string para double.
    */

    const char *cstr = "123.45";

    double numero = atof(cstr);

    printf("=== Tópico 2 - atof ===\n");
    printf("String: %s\n", cstr);
    printf("Número convertido: %f\n", numero);
    printf("\n");
}


/* =========================================================
   Tópico 3 - atoll (string -> long long)
   ========================================================= */
void exemploAtoll(void) {

    /*
        atoll significa "ASCII to Long Long".
    */

    const char *cstr = "123456789012345";

    long long numero = atoll(cstr);

    printf("=== Tópico 3 - atoll ===\n");
    printf("String: %s\n", cstr);
    printf("Número convertido: %lld\n", numero);
    printf("\n");
}


/* =========================================================
   Tópico 4 - strtol (conversão robusta)
   ========================================================= */
void exemploStrtol(void) {

    /*
        strtol é mais robusta que atoi.

        Permite identificar onde a conversão parou.
    */

    const char *cstr = "12345abc";

    char *end;

    long numero = strtol(cstr, &end, 10);

    printf("=== Tópico 4 - strtol ===\n");

    if (end == cstr) {

        printf("Nenhum número foi convertido.\n");

    } else {

        printf("String: %s\n", cstr);
        printf("Número convertido: %ld\n", numero);
        printf("Primeiro caractere não convertido: %c\n", *end);

    }

    printf("\n");
}


/* =========================================================
   Tópico 5 - strtod (string -> double robusto)
   ========================================================= */
void exemploStrtod(void) {

    /*
        strtod funciona de forma semelhante ao strtol,
        mas para números com ponto decimal.
    */

    const char *cstr = "123.45abc";

    char *end;

    double numero = strtod(cstr, &end);

    printf("=== Tópico 5 - strtod ===\n");

    if (end == cstr) {

        printf("Nenhum número foi convertido.\n");

    } else {

        printf("String: %s\n", cstr);
        printf("Número convertido: %f\n", numero);
        printf("Primeiro caractere não convertido: %c\n", *end);

    }

    printf("\n");
}


/* =========================================================
   Tópico 6 - Observações finais
   ========================================================= */
void observacoesConversao(void) {

    printf("=== Tópico 6 - Observações ===\n");

    printf("1. atoi, atof e atoll são funções simples de conversão.\n");
    printf("2. Essas funções não detectam erros facilmente.\n");
    printf("3. strtol e strtod são mais seguras.\n");
    printf("4. Elas permitem verificar onde a conversão parou.\n");
    printf("5. Essas funções são úteis ao ler dados de ficheiros ou input do utilizador.\n");

    printf("\n");
}


/* =========================================================
   Função principal
   ========================================================= */
int main(void) {

    exemploAtoi();
    exemploAtof();
    exemploAtoll();
    exemploStrtol();
    exemploStrtod();
    observacoesConversao();

    return 0;
}