#include <iostream>
using namespace std;

// ------------------------------------------------------
// BUSCA SEQUENCIAL COM SENTINELA
// Evita testar o limite do vetor dentro do loop.
// O elemento x é colocado temporariamente no final.
// ------------------------------------------------------
int buscaSequencialSentinela(int x, int n, int v[]) {

    v[n] = x; // sentinela colocado após o último elemento

    int k = 0;

    // percorre até encontrar x
    while (v[k] != x) {
        k++;
    }

    // se parou exatamente no sentinela, o valor não estava no vetor
    if (k == n) return -1;

    return k; // índice onde encontrou
}

int main() {

    int vOriginal[] = {10, 20, 30, 40, 50};

    int tamanho = sizeof(vOriginal) / sizeof(vOriginal[0]);

    // vetor auxiliar com espaço extra para o sentinela
    int v[tamanho + 1];

    // cópia do vetor original
    for (int i = 0; i < tamanho; i++) {
        v[i] = vOriginal[i];
    }

    int valor = 30;

    int resultado = buscaSequencialSentinela(valor, tamanho, v);

    if (resultado != -1) {
        cout << "Valor encontrado na posicao: " << resultado << endl;
    } else {
        cout << "Valor nao encontrado!" << endl;
    }

    return 0;
}