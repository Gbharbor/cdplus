//EX 1 Vetor de inteiro
#include <stdio.h>

int main() {
    // Declaração e inicialização de um vetor de inteiros
    int notas[5] = {10, 9, 8, 7, 6};

    // Exibindo os elementos do vetor
    printf("Notas dos alunos:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nota %d: %d\n", i + 1, notas[i]);
    }

    return 0;
}

//EX 2 Vetor de Caracteres
#include <stdio.h>

int main() {
    // Declaração e inicialização de um vetor de caracteres
    char iniciais[5] = {'A', 'B', 'C', 'D', 'E'};

    // Exibindo os elementos do vetor
    printf("Iniciais:\n");
    for (int i = 0; i < 5; i++) {
        printf("Inicial %d: %c\n", i + 1, iniciais[i]);
    }

    return 0;
}

//EX3 Vetor de numeros Flutuantes
#include <stdio.h>

int main() {
    // Declaração e inicialização de um vetor de números flutuantes
    float medias[4] = {7.5, 8.2, 6.3, 9.1};

    // Exibindo os elementos do vetor
    printf("Médias dos alunos:\n");
    for (int i = 0; i < 4; i++) {
        printf("Média %d: %.2f\n", i + 1, medias[i]);
    }

    return 0;
}
