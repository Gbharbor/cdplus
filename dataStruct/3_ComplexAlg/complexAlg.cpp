#include <iostream>
using namespace std;

// Função que encontra o maior valor de um vetor
int maximo(int vet[], int n) {
    int val_max = vet[0]; // Inicialização do maior valor

    // Invariante: val_max é o maior valor entre vet[0] e vet[j-1]
    for (int j = 1; j < n; j++) {
        if (vet[j] > val_max) {
            val_max = vet[j]; // Atualiza se encontrar valor maior
        }
    }

    return val_max; // Retorna o maior valor
}

int main() {
    int vetorMelhor[] = {1, 2, 3, 4, 5};   // Melhor caso: ordem crescente
    int vetorPior[]   = {5, 4, 3, 2, 1};   // Pior caso: maior valor no início
    int vetorMedio[]  = {3, 1, 5, 2, 4};   // Caso médio: ordem aleatória

    int n = 5;

    cout << "Melhor caso: " << maximo(vetorMelhor, n) << endl;
    cout << "Pior caso:   " << maximo(vetorPior, n) << endl;
    cout << "Caso medio:  " << maximo(vetorMedio, n) << endl;

    return 0;
}