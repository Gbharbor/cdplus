#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Exemplo 1: matriz bidimensional
// ------------------------------------------------------------
void exemploMatrizBidimensional() {
    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Acessando elementos de uma matriz
    int valor = matriz[1][2]; // Acessa o elemento da segunda linha, terceira coluna
    matriz[0][3] = 20;        // Altera o elemento da primeira linha, quarta coluna

    cout << "Elemento acessado na posicao [1][2]: " << valor << endl;

    // Percorrendo a matriz com laços for
    cout << "\nElementos da matriz bidimensional:" << endl;
    for (int i = 0; i < 3; i++) {          // Percorre as linhas
        for (int j = 0; j < 4; j++) {      // Percorre as colunas
            cout << matriz[i][j] << " ";
        }
        cout << endl; // Quebra de linha após cada linha da matriz
    }
}

// ------------------------------------------------------------
// Exemplo 2: matriz dinâmica
// ------------------------------------------------------------
void exemploMatrizDinamica() {
    int linhas = 3, colunas = 4;

    // Cria um vetor de ponteiros, onde cada ponteiro representa uma linha
    int** matrizDinamica = new int*[linhas];

    // Aloca memória para cada linha da matriz
    for (int i = 0; i < linhas; i++) {
        matrizDinamica[i] = new int[colunas];
    }

    // Preenche a matriz dinâmica com valores de exemplo
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizDinamica[i][j] = (i + 1) * (j + 1);
        }
    }

    // Exibe os elementos da matriz dinâmica
    cout << "\nElementos da matriz dinamica:" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << matrizDinamica[i][j] << " ";
        }
        cout << endl;
    }

    // Libera a memória alocada para cada linha
    for (int i = 0; i < linhas; i++) {
        delete[] matrizDinamica[i];
    }

    // Libera o vetor de ponteiros
    delete[] matrizDinamica;
}

// ------------------------------------------------------------
// Exemplo 3: matriz tridimensional
// ------------------------------------------------------------
void exemploMatrizTridimensional() {
    // Declaração e inicialização de uma matriz tridimensional 2x2x2
    int tritabela[2][2][2] = {
        {
            {9, 8},
            {7, 6}
        },
        {
            {5, 4},
            {3, 2}
        }
    };

    // Laços aninhados para percorrer a matriz tridimensional
    cout << "\nElementos da matriz tridimensional:" << endl;

    for (int i = 0; i < 2; i++) {          // Percorre a primeira dimensão
        cout << "Bloco " << i << ":" << endl;

        for (int j = 0; j < 2; j++) {      // Percorre a segunda dimensão
            for (int k = 0; k < 2; k++) {  // Percorre a terceira dimensão
                cout << tritabela[i][j][k] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
}

// ------------------------------------------------------------
// Função principal
// ------------------------------------------------------------
int main() {
    exemploMatrizBidimensional();
    exemploMatrizDinamica();
    exemploMatrizTridimensional();

    return 0;
}