//Exemplo 1: Estrutura de Dados para Alunos
#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 3 // Definindo o número máximo de alunos

// Definindo a estrutura para armazenar dados do aluno
struct Aluno {
    char nome[50];
    float notas[3];
    float media;
};

// Função para calcular a média das notas
float calcular_media(float notas[], int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += notas[i];
    }
    return soma / tamanho;
}

int main() {
    struct Aluno alunos[MAX_ALUNOS];// semelhante aoi object ao JS

    // Entrada de dados
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0; // Remove nova linha

        printf("Digite as 3 notas de %s:\n", alunos[i].nome);
        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
        alunos[i].media = calcular_media(alunos[i].notas, 3);
        getchar(); // Limpar o buffer do stdin
    }

    // Exibindo os resultados
    printf("\nResultados:\n");
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("Nome: %s, Média: %.2f\n", alunos[i].nome, alunos[i].media);
    }

    return 0;
}
//Ordenacao de Notas
#include <stdio.h>

#define MAX_ALUNOS 5 // Definindo o número máximo de alunos

void ordenar_notas(float notas[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (notas[i] > notas[j]) {
                float temp = notas[i]; // temp var temporaly
                notas[i] = notas[j];
                notas[j] = temp;
            }
        }
    }
}

int main() {
    float notas[MAX_ALUNOS];

    // Entrada de dados
    printf("Digite as notas dos alunos:\n");
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    // Ordenando as notas
    ordenar_notas(notas, MAX_ALUNOS);

    // Exibindo as notas ordenadas
    printf("\nNotas em ordem crescente:\n");
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("Nota %d: %.2f\n", i + 1, notas[i]);
    }

    return 0;
}