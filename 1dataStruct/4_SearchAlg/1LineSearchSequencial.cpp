#include <iostream>
using namespace std;

int buscaSequencial(int x, int n, int v[]) {
    for (int k = 0; k < n; k++) {
        if (v[k] == x) {
            return k; // Retorna o índice onde encontrou
        }
    }
    return -1; // Não encontrado
}

int main() {
    int vetor[] = {4, 8, 15, 16, 23, 42};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor = 15;

    int resultado = buscaSequencial(valor, tamanho, vetor);

    if (resultado != -1)
        cout << "Valor encontrado na posição: " << resultado << endl;
    else
        cout << "Valor não encontrado!" << endl;

    return 0;
}
