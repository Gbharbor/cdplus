#include <iostream>
using namespace std;

// ------------------------------------------------------
// FUNCAO QUE ENCONTRA O MAIOR ELEMENTO DE UM VETOR
// Complexidade: O(n)
// Percorre o vetor comparando cada elemento.
// ------------------------------------------------------
int maximo(const int vet[], int n) {

    // Segurança: evita acesso inválido se n == 0
    if (n <= 0) return -1;

    int val_max = vet[0]; // assume inicialmente o primeiro elemento como máximo

    // Invariante do loop:
    // val_max contém o maior valor entre vet[0] e vet[j-1]
    for (int j = 1; j < n; j++) {

        if (vet[j] > val_max) {
            val_max = vet[j]; // atualiza se encontrar valor maior
        }

    }

    return val_max;
}

int main() {

    // Exemplos para análise de comportamento do algoritmo
    int vetorMelhor[] = {1, 2, 3, 4, 5};  // melhor caso (ordem crescente)
    int vetorPior[]   = {5, 4, 3, 2, 1};  // pior caso (maior elemento no início)
    int vetorMedio[]  = {3, 1, 5, 2, 4};  // caso médio (ordem aleatória)

    int n = 5;

    cout << "Melhor caso: " << maximo(vetorMelhor, n) << endl;
    cout << "Pior caso:   " << maximo(vetorPior, n) << endl;
    cout << "Caso medio:  " << maximo(vetorMedio, n) << endl;

    return 0;
}