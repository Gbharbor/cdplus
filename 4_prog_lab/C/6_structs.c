#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 3
#define QTD_NOTAS 3
#define MAX_NOTAS_ORDENAR 5

/*
    Aula 06 - Structs, Vetores e Ordenação
    Exemplo com alunos e exemplo com ordenação de notas
*/

/* =========================================================
   Tópico 1 - Estrutura de dados para alunos
   ========================================================= */

/*
    A struct Aluno funciona como um "molde" para guardar
    várias informações relacionadas ao mesmo aluno.

    Comparando com JavaScript:
    é parecido com um objeto que possui propriedades.

    Exemplo de campos:
    - nome
    - notas
    - média
*/
struct Aluno {
    char nome[50];
    float notas[QTD_NOTAS];
    float media;
};

/* =========================================================
   Tópico 2 - Função para calcular média
   ========================================================= */
float calcularMedia(float notas[], int tamanho) {
    float soma = 0.0f;

    for (int i = 0; i < tamanho; i++) {
        soma += notas[i];
    }

    return soma / tamanho;
}

/* =========================================================
   Tópico 3 - Cadastro de alunos e cálculo da média
   ========================================================= */
void exemploAlunos(void) {
    struct Aluno alunos[MAX_ALUNOS];

    printf("=== Exemplo 1 - Estrutura de Dados para Alunos ===\n");

    /* Entrada de dados */
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        /* Remove o \n que o fgets pode guardar */
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Digite as %d notas de %s:\n", QTD_NOTAS, alunos[i].nome);

        for (int j = 0; j < QTD_NOTAS; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }

        alunos[i].media = calcularMedia(alunos[i].notas, QTD_NOTAS);

        /* Limpa o ENTER restante no buffer antes do próximo fgets */
        getchar();
    }

    /* Exibição dos resultados */
    printf("\nResultados:\n");

    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("Nome: %s | Média: %.2f\n", alunos[i].nome, alunos[i].media);
    }

    printf("\n");
}

/* =========================================================
   Tópico 4 - Ordenação de notas
   ========================================================= */

/*
    Esta função ordena as notas em ordem crescente.
    Foi usado um método simples de comparação e troca.
*/
void ordenarNotas(float notas[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (notas[i] > notas[j]) {
                float temp = notas[i];
                notas[i] = notas[j];
                notas[j] = temp;
            }
        }
    }
}

/* =========================================================
   Tópico 5 - Leitura e ordenação de notas
   ========================================================= */
void exemploOrdenacao(void) {
    float notas[MAX_NOTAS_ORDENAR];

    printf("=== Exemplo 2 - Ordenação de Notas ===\n");

    printf("Digite as notas dos alunos:\n");
    for (int i = 0; i < MAX_NOTAS_ORDENAR; i++) {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    ordenarNotas(notas, MAX_NOTAS_ORDENAR);

    printf("\nNotas em ordem crescente:\n");
    for (int i = 0; i < MAX_NOTAS_ORDENAR; i++) {
        printf("Nota %d: %.2f\n", i + 1, notas[i]);
    }

    printf("\n");
}

/* =========================================================
   Função principal
   ========================================================= */
int main(void) {
    exemploAlunos();
    exemploOrdenacao();

    return 0;
}