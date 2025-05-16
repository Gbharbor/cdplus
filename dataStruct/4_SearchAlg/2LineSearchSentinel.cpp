#include <iostream>
using namespace std;

int buscaSequencialSentinela(int x, int n, int v[]) {
    v[n] = x; // Define o sentinela
    int k = 0;
    while (v[k] != x) {
        k++;
    }
    if (k == n) return -1; // Não encontrado
    return k;
}

int main() {
    int vOriginal[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(vOriginal) / sizeof(vOriginal[0]);

    int v[tamanho + 1]; // vetor com espaço extra
    for (int i = 0; i < tamanho; i++) {
        v[i] = vOriginal[i];
    }

    int valor = 30;
    int resultado = buscaSequencialSentinela(valor, tamanho, v);

    if (resultado != -1)
        cout << "Valor encontrado na posição: " << resultado << endl;
    else
        cout << "Valor não encontrado!" << endl;

    return 0;
}
