#include <stdio.h>
#include <string.h>

/*
    Aula 11 - Headers em C

    Em C, headers são ficheiros com extensão .h
    que contêm declarações de funções, tipos,
    constantes e macros.

    Exemplo:
    - stdio.h   -> entrada e saída
    - string.h  -> manipulação de strings

    O comando #include serve para incluir
    o conteúdo desses headers no programa.
*/

/* =========================================================
   Tópico 1 - Exemplo com stdio.h
   ========================================================= */
void exemploStdio(void) {
    printf("=== Tópico 1 - stdio.h ===\n");
    printf("A biblioteca stdio.h é usada para entrada e saída.\n");
    printf("Exemplos: printf, scanf, fgets, puts\n");
    printf("\n");
}

/* =========================================================
   Tópico 2 - Exemplo com string.h
   ========================================================= */
void exemploString(void) {
    char origem[] = "Ola";
    char destino[20];
    char texto[30] = "Hello";
    char texto2[] = " World";

    printf("=== Tópico 2 - string.h ===\n");

    /* strcpy */
    strcpy(destino, origem);
    printf("strcpy -> destino = %s\n", destino);

    /* strcat */
    strcat(texto, texto2);
    printf("strcat -> %s\n", texto);

    /* strlen */
    printf("strlen -> comprimento de \"%s\" = %zu\n", texto, strlen(texto));

    /* strcmp */
    printf("strcmp(\"Ana\", \"Bia\") = %d\n", strcmp("Ana", "Bia"));

    /* strchr */
    char *primeira = strchr(texto, 'o');
    if (primeira != NULL) {
        printf("strchr -> primeira ocorrência de 'o': %s\n", primeira);
    }

    /* strrchr */
    char *ultima = strrchr(texto, 'o');
    if (ultima != NULL) {
        printf("strrchr -> última ocorrência de 'o': %s\n", ultima);
    }

    printf("\n");
}

/* =========================================================
   Tópico 3 - Observações sobre headers
   ========================================================= */
void observacoesHeaders(void) {
    printf("=== Tópico 3 - Observações sobre headers ===\n");
    printf("1. #include <stdio.h> inclui funções de entrada e saída.\n");
    printf("2. #include <string.h> inclui funções de manipulação de strings.\n");
    printf("3. Headers evitam reescrever declarações manualmente.\n");
    printf("4. O ficheiro .h normalmente não contém o programa principal.\n");
    printf("5. O código principal costuma ficar em ficheiros .c.\n");
    printf("\n");
}

/* =========================================================
   Função principal
   ========================================================= */
int main(void) {
    exemploStdio();
    exemploString();
    observacoesHeaders();

    return 0;
}