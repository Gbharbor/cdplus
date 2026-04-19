/*
Faça um programa na linguagem C/C++ que implemente o algoritmo de ordenação Insertion-Sort. O programa deverá permitir que o usuário informe n valores inteiros e visualize os valores ordenados em ordem crescente na tela.
*/
#include <iostream>
using namespace std;

// Função de ordenação Insertion Sort
void insertionSort(int* vetor, int n) {
    for (int i = 1; i < n; i++) {
        int chave = vetor[i];
        int j = i - 1;

        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

int main() {
    int n;

    // Solicita a quantidade de números
    cout << "Informe a quantidade de valores: ";
    cin >> n;

    // Aloca dinamicamente o vetor
    int* vetor = new int[n];

    // Lê os valores
    cout << "Informe os " << n << " valores:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> vetor[i];
    }

    // Ordena os valores
    insertionSort(vetor, n);

    // Exibe o vetor ordenado
    cout << "Valores ordenados: ";
    for (int i = 0; i < n; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Libera memória
    delete[] vetor;

    return 0;
}