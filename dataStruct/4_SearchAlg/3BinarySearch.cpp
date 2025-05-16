#include <iostream>
using namespace std;

int buscaBinaria(int x, int n, int v[]) {
    int esquerda = 0, direita = n - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if (v[meio] == x) {
            return meio; // Valor encontrado
        } else if (v[meio] < x) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1; // Valor não encontrado
}

int main() {
    int vetor[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor = 20;

    int resultado = buscaBinaria(valor, tamanho, vetor);

    if (resultado != -1)
        cout << "Valor encontrado na posição: " << resultado << endl;
    else
        cout << "Valor não encontrado!" << endl;

    return 0;
}
