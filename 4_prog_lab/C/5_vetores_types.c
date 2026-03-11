#include <stdio.h>

/*
    Aula 05 - Vetores com Diferentes Tipos de Dados
    int, char e float
*/

/* =========================================================
   Exemplo 1 - Vetor de inteiros
   ========================================================= */
void vetorInteiros() {

    int notas[5] = {10, 9, 8, 7, 6};

    printf("=== Vetor de inteiros ===\n");

    for (int i = 0; i < 5; i++) {

        printf("Nota %d: %d\n", i + 1, notas[i]);

    }

    printf("\n");
}

/* =========================================================
   Exemplo 2 - Vetor de caracteres
   ========================================================= */
void vetorCaracteres() {

    char iniciais[5] = {'A', 'B', 'C', 'D', 'E'};

    printf("=== Vetor de caracteres ===\n");

    for (int i = 0; i < 5; i++) {

        printf("Inicial %d: %c\n", i + 1, iniciais[i]);

    }

    printf("\n");
}

/* =========================================================
   Exemplo 3 - Vetor de números flutuantes
   ========================================================= */
void vetorFloat() {

    float medias[4] = {7.5, 8.2, 6.3, 9.1};

    printf("=== Vetor de números flutuantes ===\n");

    for (int i = 0; i < 4; i++) {

        printf("Média %d: %.2f\n", i + 1, medias[i]);

    }

    printf("\n");
}

/* =========================================================
   Função principal
   ========================================================= */
int main() {

    vetorInteiros();
    vetorCaracteres();
    vetorFloat();

    return 0;
}