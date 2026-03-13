// ------------------------------------------------------------
// Exemplo de matriz bidimensional
// Armazena notas de alunos em várias disciplinas
// ------------------------------------------------------------

#include <stdio.h>

#define ALUNOS 3        // Número de alunos
#define DISCIPLINAS 4   // Número de disciplinas

int main() {

    // Matriz que armazena as notas dos alunos
    float notas[ALUNOS][DISCIPLINAS];

    // Vetor para armazenar a média de cada aluno
    float medias[ALUNOS];


    // --------------------------------------------------------
    // Entrada de dados
    // --------------------------------------------------------
    for (int i = 0; i < ALUNOS; i++) {

        printf("Digite as notas do aluno %d:\n", i + 1);

        for (int j = 0; j < DISCIPLINAS; j++) {

            printf("Nota da disciplina %d: ", j + 1);
            scanf("%f", &notas[i][j]);

        }
    }


    // --------------------------------------------------------
    // Cálculo das médias
    // --------------------------------------------------------
    for (int i = 0; i < ALUNOS; i++) {

        float soma = 0;

        for (int j = 0; j < DISCIPLINAS; j++) {
            soma += notas[i][j];
        }

        medias[i] = soma / DISCIPLINAS;
    }


    // --------------------------------------------------------
    // Exibição dos resultados
    // --------------------------------------------------------
    printf("\nMedias dos alunos:\n");

    for (int i = 0; i < ALUNOS; i++) {
        printf("Media do aluno %d: %.2f\n", i + 1, medias[i]);
    }

    return 0;
}