
//Matriz tridimensional
#include <stdio.h>

#define ALUNOS 3 // Número de alunos
#define DISCIPLINAS 4 // Número de disciplinas
#define BIMESTRES 2 // Número de bimestres

int main() {
    // Declaração da matriz de notas
    float notas[ALUNOS][DISCIPLINAS][BIMESTRES];
    float medias[ALUNOS][DISCIPLINAS];

    // Entrada de dados
    for (int i = 0; i < ALUNOS; i++) {
        printf("Digite as notas do aluno %d:\n", i + 1);
        for (int j = 0; j < DISCIPLINAS; j++) {
            for (int k = 0; k < BIMESTRES; k++) {
                printf("Nota da disciplina %d, bimestre %d: ", j + 1, k + 1);
                scanf("%f", &notas[i][j][k]);
            }
        }
    }

    // Cálculo da média para cada aluno por disciplina
    for (int i = 0; i < ALUNOS; i++) {
        for (int j = 0; j < DISCIPLINAS; j++) {
            float soma = 0;
            for (int k = 0; k < BIMESTRES; k++) {
                soma += notas[i][j][k];
            }
            medias[i][j] = soma / BIMESTRES; // Calcula a média
        }
    }

    // Exibindo as médias
    printf("\nMédias dos alunos por disciplina:\n");
    for (int i = 0; i < ALUNOS; i++) {
        for (int j = 0; j < DISCIPLINAS; j++) {
            printf("Média do aluno %d na disciplina %d: %.2f\n", i + 1, j + 1, medias[i][j]);
        }
    }

    return 0;
}