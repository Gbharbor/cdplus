#include <stdio.h>

/*
    Aula 07 - Matrizes Bidimensionais em C

    Uma matriz bidimensional pode ser vista como uma tabela:
    linhas   -> alunos
    colunas  -> disciplinas
*/

#define ALUNOS 3
#define DISCIPLINAS 4

int main(void) {

    /* =========================================================
       Declaração das estruturas de dados
       ========================================================= */

    float notas[ALUNOS][DISCIPLINAS]; // matriz de notas
    float medias[ALUNOS];             // vetor para médias

    /* =========================================================
       Entrada de dados
       ========================================================= */

    for (int i = 0; i < ALUNOS; i++) {

        printf("Digite as notas do aluno %d:\n", i + 1);

        for (int j = 0; j < DISCIPLINAS; j++) {

            printf("Nota da disciplina %d: ", j + 1);
            scanf("%f", &notas[i][j]);

        }
    }

    /* =========================================================
       Cálculo das médias
       ========================================================= */

    for (int i = 0; i < ALUNOS; i++) {

        float soma = 0;

        for (int j = 0; j < DISCIPLINAS; j++) {

            soma += notas[i][j];

        }

        medias[i] = soma / DISCIPLINAS;
    }

    /* =========================================================
       Exibição dos resultados
       ========================================================= */

    printf("\nMédias dos alunos:\n");

    for (int i = 0; i < ALUNOS; i++) {

        printf("Média do aluno %d: %.2f\n", i + 1, medias[i]);

    }

    return 0;
}