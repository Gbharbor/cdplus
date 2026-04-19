#include <iostream>
using namespace std;

// ------------------------------------------------------
// BUSCA SEQUENCIAL (LINEAR SEARCH)
// Percorre o vetor elemento por elemento até encontrar x.
// Retorna o índice do elemento ou -1 se não existir.
// ------------------------------------------------------
int buscaSequencial(int x, int n, const int v[]) {

    for (int k = 0; k < n; k++) {

        if (v[k] == x) {
            return k; // elemento encontrado
        }

    }

    return -1; // elemento não encontrado
}

int main() {

    int vetor[] = {4, 8, 15, 16, 23, 42};

    // cálculo automático do tamanho do vetor
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int valor = 15;

    int resultado = buscaSequencial(valor, tamanho, vetor);

    if (resultado != -1) {
        cout << "Valor encontrado na posicao: " << resultado << endl;
    } else {
        cout << "Valor nao encontrado!" << endl;
    }

    return 0;
}