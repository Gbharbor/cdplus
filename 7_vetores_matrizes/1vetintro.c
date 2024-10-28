//EXEMPLO EM C 
/*
Faça um programa que peça 3 números inteiros
ao usuário, armazene em um vetor, depois mostre o valor de
cada elemento do vetor, assim como seu índice.
*/
//opcao 1
#include <stdio.h>

int main() {
    int NUMERO[3], indice;

    // Lê os elementos do array a partir da entrada do usuário
    for (indice = 0; indice <= 2; indice++) {
        printf("Entre com o número %d: ", indice + 1);
        scanf("%d", &NUMERO[indice]);
    }

    // Exibe os elementos armazenados no array
    for (indice = 0; indice <= 2; indice++) {
        printf("Número %d = %d\n", indice + 1, NUMERO[indice]);
    }

    return 0;
}

//opcao 2
#include <stdio.h>

int main() {
    int numeros[3]; // Declara um vetor para armazenar os 3 números
    int i;

    // Solicita ao usuário que insira os 3 números
    for (i = 0; i < 3; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Exibe cada elemento do vetor juntamente com seu índice
    printf("\nValores e índices do vetor:\n");
    for (i = 0; i < 3; i++) {
        printf("Índice %d -> Valor: %d\n", i, numeros[i]);
    }

    return 0;
}
/*
Faça um programa em C que peça ao usuário duas
notas que ele tirou e mostre a média.
Use vetores! Aliás, use somente um vetor para essas
três variáveis.
*/
#include <stdio.h>

int main() {
    float notas[3];  // Declara um vetor para armazenar duas notas e a média

    // Solicita as duas notas ao usuário
    printf("Digite a primeira nota: ");
    scanf("%f", &notas[0]);

    printf("Digite a segunda nota: ");
    scanf("%f", &notas[1]);

    // Calcula a média e armazena na terceira posição do vetor
    notas[2] = (notas[0] + notas[1]) / 2;

    // Exibe a média
    printf("A média das notas %.2f e %.2f é: %.2f\n", notas[0], notas[1], notas[2]);

    return 0;
}