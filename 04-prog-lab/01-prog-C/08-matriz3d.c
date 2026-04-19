#include <stdio.h>

/*
    Aula 08 - Matrizes Tridimensionais

    Estrutura dos dados:

    Alunos       -> dimensão 1
    Disciplinas  -> dimensão 2
    Bimestres    -> dimensão 3

    notas[ALUNOS][DISCIPLINAS][BIMESTRES]
*/

#define ALUNOS 3
#define DISCIPLINAS 4
#define BIMESTRES 2

int main(void) {

    /* =========================================================
       Declaração das estruturas
       ========================================================= */

    float notas[ALUNOS][DISCIPLINAS][BIMESTRES];
    float medias[ALUNOS][DISCIPLINAS];

    /* =========================================================
       Entrada de dados
       ========================================================= */

    for (int i = 0; i < ALUNOS; i++) {

        printf("Digite as notas do aluno %d:\n", i + 1);

        for (int j = 0; j < DISCIPLINAS; j++) {

            for (int k = 0; k < BIMESTRES; k++) {

                printf("Nota da disciplina %d, bimestre %d: ",
                       j + 1, k + 1);

                scanf("%f", &notas[i][j][k]);

            }
        }
    }

    /* =========================================================
       Cálculo das médias por disciplina
       ========================================================= */

    for (int i = 0; i < ALUNOS; i++) {

        for (int j = 0; j < DISCIPLINAS; j++) {

            float soma = 0;

            for (int k = 0; k < BIMESTRES; k++) {

                soma += notas[i][j][k];

            }

            medias[i][j] = soma / BIMESTRES;

        }
    }

    /* =========================================================
       Exibição dos resultados
       ========================================================= */

    printf("\nMédias dos alunos por disciplina:\n");

    for (int i = 0; i < ALUNOS; i++) {

        for (int j = 0; j < DISCIPLINAS; j++) {

            printf("Aluno %d - Disciplina %d -> Média: %.2f\n",
                   i + 1, j + 1, medias[i][j]);

        }
    }

    return 0;
}