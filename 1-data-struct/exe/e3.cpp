/*
Faça um programa na linguagem C/C++ que implemente o método de Busca Binária. O programa deverá conter um vetor alocado dinamicamente de tamanho n, onde n deverá ser fornecido pelo usuário. A seguir, o programa deverá solicitar ao usuário que informe os n valores para o vetor. Feito isso, o programa também deverá pedir para que o usuário informe o valor a ser buscado. Por fim, o programa deverá mostrar na tela o resultado da busca. Obs: suponha que os valores serão fornecidos pelo usuário já ordenados.
*/
#include <iostream>
using namespace std;

// Função de busca binária
int buscaBinaria(int* vetor, int tamanho, int alvo) {
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if (vetor[meio] == alvo)
            return meio; // encontrado
        else if (vetor[meio] < alvo)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }

    return -1; // não encontrado
}

int main() {
    int n, valorBusca;

    // Solicita o tamanho do vetor
    cout << "Informe o tamanho do vetor: ";
    cin >> n;

    // Alocação dinâmica do vetor
    int* vetor = new int[n];

    // Entrada dos elementos (ordenados)
    cout << "Informe " << n << " valores (ordenados):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> vetor[i];
    }

    // Solicita o valor a ser buscado
    cout << "Informe o valor a ser buscado: ";
    cin >> valorBusca;

    // Realiza a busca binária
    int posicao = buscaBinaria(vetor, n, valorBusca);

    // Exibe o resultado
    if (posicao != -1)
        cout << "Valor encontrado na posicao " << posicao << "." << endl;
    else
        cout << "Valor nao encontrado no vetor." << endl;

    // Libera a memória alocada
    delete[] vetor;

    return 0;
}
