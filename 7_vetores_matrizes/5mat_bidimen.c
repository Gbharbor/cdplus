//MATRIZ BIDIMENSIONAL
#include <stdio.h>

#define ALUNOS 3 // Número de alunos
#define DISCIPLINAS 4 // Número de disciplinas

int main() {
    // Declaração da matriz de notas
    float notas[ALUNOS][DISCIPLINAS];
    float medias[ALUNOS];

    // Entrada de dados
    for (int i = 0; i < ALUNOS; i++) {
        printf("Digite as notas do aluno %d:\n", i + 1);
        for (int j = 0; j < DISCIPLINAS; j++) {
            printf("Nota da disciplina %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    // Cálculo da média para cada aluno
    for (int i = 0; i < ALUNOS; i++) {
        float soma = 0;
        for (int j = 0; j < DISCIPLINAS; j++) {
            soma += notas[i][j];
        }
        medias[i] = soma / DISCIPLINAS; // Calcula a média
    }

    // Exibindo as médias
    printf("\nMédias dos alunos:\n");
    for (int i = 0; i < ALUNOS; i++) {
        printf("Média do aluno %d: %.2f\n", i + 1, medias[i]);
    }

    return 0;
}