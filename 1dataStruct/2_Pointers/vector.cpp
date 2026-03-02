#include <iostream>
using namespace std;

// Função que soma os elementos de um vetor usando ponteiro
int somaVetor(int *vetor, int n) {
    int soma = 0;
    int *apt = vetor;
    int *apt_fim = vetor + n;

    for (; apt < apt_fim; apt++) {
        soma += *apt;
    }
    return soma;
}

// Função que exibe os elementos de uma matriz usando ponteiros
void exibeMat(int mat[3][3], int linhas, int colunas) {
    int *apt, *inicio, *fim;
    inicio = &mat[0][0];
    fim = inicio + (linhas * colunas);

    for (apt = inicio; apt < fim; apt++) {
        cout << *apt << " ";
    }
    cout << endl;
}

int main() {
    // -----------------------------
    // 1. Usando ponteiro com vetor
    // -----------------------------
    int vetor[5] = {10, 20, 30, 40, 50};

    int *apt_vetor = vetor; // aponta para o primeiro elemento
    cout << "Primeiro elemento do vetor: " << *apt_vetor << endl;

    // Acessando posição específica com &vetor[i]
    int *apt_vetor2 = &vetor[2];
    cout << "Elemento na posição 2: " << *apt_vetor2 << endl;

    // Aritmética com ponteiros
    cout << "Elemento na posição 3 (com ponteiro): " << *(vetor + 3) << endl;

    // -----------------------------
    // 2. Soma dos elementos com ponteiro
    // -----------------------------
    int resultado = somaVetor(vetor, 5);
    cout << "Soma dos elementos do vetor: " << resultado << endl;

    // -----------------------------
    // 3. Ponteiro para matriz
    // -----------------------------
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Elementos da matriz (usando ponteiros): ";
    exibeMat(matriz, 3, 3);

    // -----------------------------
    // 4. Alocação dinâmica de vetor
    // -----------------------------
    double *valores = new double[3];
    valores[0] = 1.1;
    valores[1] = 2.2;
    valores[2] = 3.3;

    cout << "Vetor alocado dinamicamente: ";
    for (int i = 0; i < 3; i++) {
        cout << valores[i] << " ";
    }
    cout << endl;

    delete[] valores; // desalocando memória

    // -----------------------------
    // 5. Ponteiro para ponteiro
    // -----------------------------
    int numero = 100;
    int *apt = &numero;
    int **apt_duplo = &apt;

    cout << "Endereço de apt_duplo: " << &apt_duplo << endl;
    cout << "Conteúdo de apt_duplo (endereço de apt): " << apt_duplo << endl;
    cout << "Conteúdo de *apt_duplo (endereço de numero): " << *apt_duplo << endl;
    cout << "Conteúdo de **apt_duplo (valor de numero): " << **apt_duplo << endl;

    return 0;
}
