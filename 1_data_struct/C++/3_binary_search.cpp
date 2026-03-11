#include <iostream>
using namespace std;

// ------------------------------------------------------
// BUSCA BINÁRIA
// O vetor deve estar ORDENADO.
// Retorna o índice do elemento encontrado ou -1 se não existir.
// ------------------------------------------------------
int buscaBinaria(int x, int n, const int v[]) {
    int esquerda = 0;
    int direita = n - 1;

    while (esquerda <= direita) {

        // cálculo seguro do meio
        int meio = esquerda + (direita - esquerda) / 2;

        if (v[meio] == x) {
            return meio; // elemento encontrado
        }

        if (v[meio] < x) {
            esquerda = meio + 1; // busca na metade direita
        } else {
            direita = meio - 1;  // busca na metade esquerda
        }
    }

    return -1; // elemento não encontrado
}

int main() {

    // vetor ordenado (requisito da busca binária)
    int vetor[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

    // cálculo automático do tamanho do vetor
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int valor = 20;

    int resultado = buscaBinaria(valor, tamanho, vetor);

    if (resultado != -1) {
        cout << "Valor encontrado na posição: " << resultado << endl;
    } else {
        cout << "Valor não encontrado!" << endl;
    }

    return 0;
}