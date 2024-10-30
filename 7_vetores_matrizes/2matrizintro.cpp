#include <iostream>
using namespace std;

/*
MATRIZES
Em C e C++, uma matriz é uma estrutura de dados que consiste em um array bidimensional.
Em vez de armazenar dados em uma linha única, como em um vetor, uma matriz armazena dados em forma de linhas e colunas, como uma tabela.
A seguir, veremos os principais conceitos sobre o uso de matrizes em C e C++.
*/

// Função para demonstrar matrizes bidimensionais
void exemploMatrizBidimensional() {
    // Declaração e Inicialização de Matrizes
    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Acessando Elementos de uma Matriz
    int valor = matriz[1][2]; // Acessa o elemento na segunda linha, terceira coluna
    matriz[0][3] = 20;        // Altera o elemento na primeira linha, quarta coluna para 20

    // Percorrendo a Matriz com `for`
    cout << "Elementos da matriz:" << endl;
    for (int i = 0; i < 3; i++) {           // Percorre as linhas
        for (int j = 0; j < 4; j++) {       // Percorre as colunas
            cout << matriz[i][j] << " ";
        }
        cout << endl;                       // Quebra de linha após cada linha da matriz
    }
}

// Função para demonstrar matrizes dinâmicas
void exemploMatrizDinamica() {
    int linhas = 3, colunas = 4;
    int** matrizDinamica = new int*[linhas]; // Cria um array de ponteiros para as linhas

    for (int i = 0; i < linhas; i++) {
        matrizDinamica[i] = new int[colunas]; // Cada ponteiro aponta para um array de colunas
    }

    // Exemplo de uso: preenchendo a matriz dinâmica com valores
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizDinamica[i][j] = (i + 1) * (j + 1); // Atribui um valor de exemplo
        }
    }

    // Exibe os elementos da matriz dinâmica
    cout << "\nElementos da matriz dinâmica:" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << matrizDinamica[i][j] << " ";
        }
        cout << endl;
    }

    // Libera a memória alocada
    for (int i = 0; i < linhas; i++) {
        delete[] matrizDinamica[i]; // Libera cada linha
    }
    delete[] matrizDinamica; // Libera o array de ponteiros
}

// Função para demonstrar matrizes tridimensionais
void exemploMatrizTridimensional() {
    // Declaração e inicialização de uma matriz tridimensional 2x2x2
    int tritabela[2][2][2] = {{{9, 8}, {7, 6}}, {{5, 4}, {3, 2}}};
    
    // Laços aninhados para percorrer a matriz tridimensional
    cout << "\nElementos da matriz tridimensional:" << endl;
    for (int i = 0; i < 2; i++) {              // Itera sobre a primeira dimensão
        for (int j = 0; j < 2; j++) {          // Itera sobre a segunda dimensão
            for (int k = 0; k < 2; k++) {      // Itera sobre a terceira dimensão
                cout << tritabela[i][j][k] << " "; // Acessa e imprime o elemento atual
            }
            cout << endl; // Nova linha após percorrer a terceira dimensão
        }
        cout << endl; // Nova linha após percorrer a segunda dimensão
    }
}

int main() {
    // Chamadas das funções para demonstrar o uso de matrizes
    exemploMatrizBidimensional();
    exemploMatrizDinamica();
    exemploMatrizTridimensional();

    return 0; // Retorna 0 para indicar que o programa terminou corretamente
}