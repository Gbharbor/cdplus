#include <iostream>
using namespace std;

// ======================================================
// FUNCAO QUE SOMA OS ELEMENTOS DE UM VETOR USANDO PONTEIROS
// ======================================================
// Recebe o endereco do primeiro elemento do vetor e a quantidade
// de elementos. Depois percorre o vetor com aritmetica de ponteiros.
int somaVetor(int *vetor, int n) {
    int soma = 0;

    // Ponteiro que comeca no inicio do vetor
    int *apt = vetor;

    // Ponteiro que marca o fim logico do vetor
    int *apt_fim = vetor + n;

    // Percorre do inicio ate antes do fim
    for (; apt < apt_fim; apt++) {
        soma += *apt;
    }

    return soma;
}

// ======================================================
// FUNCAO QUE EXIBE OS ELEMENTOS DE UMA MATRIZ USANDO PONTEIROS
// ======================================================
// Esta funcao recebe uma matriz 3x3 e percorre seus elementos
// como se estivessem em sequencia na memoria.
void exibeMat(int mat[3][3], int linhas, int colunas) {
    int *apt;
    int *inicio;
    int *fim;

    // Endereco do primeiro elemento da matriz
    inicio = &mat[0][0];

    // Endereco logo apos o ultimo elemento
    fim = inicio + (linhas * colunas);

    // Percorre todos os elementos linearmente
    for (apt = inicio; apt < fim; apt++) {
        cout << *apt << " ";
    }

    cout << endl;
}

int main() {

    // ======================================================
    // PARTE 1 - PONTEIRO COM VETOR
    // ======================================================
    int vetor[5] = {10, 20, 30, 40, 50};

    // O nome do vetor representa o endereco do primeiro elemento
    int *apt_vetor = vetor;

    cout << "Primeiro elemento do vetor: " << *apt_vetor << endl;

    // Acessando uma posicao especifica usando o endereco do elemento
    int *apt_vetor2 = &vetor[2];
    cout << "Elemento na posicao 2: " << *apt_vetor2 << endl;

    // Aritmetica com ponteiros:
    // vetor + 3 aponta para o quarto elemento
    cout << "Elemento na posicao 3 (com ponteiro): " << *(vetor + 3) << endl;

    cout << endl;


    // ======================================================
    // PARTE 2 - SOMA DOS ELEMENTOS DO VETOR
    // ======================================================
    int resultado = somaVetor(vetor, 5);

    cout << "Soma dos elementos do vetor: " << resultado << endl;

    cout << endl;


    // ======================================================
    // PARTE 3 - PONTEIRO PARA MATRIZ
    // ======================================================
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Elementos da matriz (usando ponteiros): ";
    exibeMat(matriz, 3, 3);

    cout << endl;


    // ======================================================
    // PARTE 4 - ALOCACAO DINAMICA DE VETOR
    // ======================================================
    // new[] aloca memoria dinamicamente para 3 elementos do tipo double
    double *valores = new double[3];

    valores[0] = 1.1;
    valores[1] = 2.2;
    valores[2] = 3.3;

    cout << "Vetor alocado dinamicamente: ";
    for (int i = 0; i < 3; i++) {
        cout << valores[i] << " ";
    }
    cout << endl;

    // delete[] deve ser usado para memoria alocada com new[]
    delete[] valores;

    cout << endl;


    // ======================================================
    // PARTE 5 - PONTEIRO PARA PONTEIRO
    // ======================================================
    int numero = 100;

    // Ponteiro simples: guarda o endereco de numero
    int *apt = &numero;

    // Ponteiro duplo: guarda o endereco do ponteiro apt
    int **apt_duplo = &apt;

    // &apt_duplo -> endereco da variavel apt_duplo
    cout << "Endereco de apt_duplo: " << &apt_duplo << endl;

    // apt_duplo -> conteudo de apt_duplo = endereco de apt
    cout << "Conteudo de apt_duplo (endereco de apt): " << apt_duplo << endl;

    // *apt_duplo -> conteudo de apt = endereco de numero
    cout << "Conteudo de *apt_duplo (endereco de numero): " << *apt_duplo << endl;

    // **apt_duplo -> valor de numero
    cout << "Conteudo de **apt_duplo (valor de numero): " << **apt_duplo << endl;

    return 0;
}