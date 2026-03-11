#include <iostream>
using namespace std;

// ==========================================================
// EXEMPLO 1 - TABELA DE MULTIPLICACAO
// ==========================================================
void exemploTabelaMultiplicacao() {
    cout << "EXEMPLO 1: Tabela de multiplicacao" << endl;

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }

    cout << endl;
}

// ==========================================================
// EXEMPLO 2 - MATRIZ 3x3
// ==========================================================
void exemploMatriz3x3() {
    cout << "EXEMPLO 2: Matriz 3x3" << endl;

    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
}

// ==========================================================
// EXEMPLO 3 - TRIANGULO DE PASCAL
// ==========================================================
void exemploTrianguloPascal() {
    cout << "EXEMPLO 3: Triangulo de Pascal" << endl;

    const int linhas = 5;
    int tri[5][5] = {0};

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j <= i; j++) {

            // Primeiro e ultimo elemento de cada linha valem 1
            if (j == 0 || j == i) {
                tri[i][j] = 1;
            } else {
                tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
            }

            cout << tri[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

// ==========================================================
// EXEMPLO 4 - QUADRADO DE ASTERISCOS
// ==========================================================
void exemploQuadradoAsteriscos() {
    cout << "EXEMPLO 4: Impressao de quadrado de asteriscos" << endl;

    int n;
    cout << "Digite o tamanho do quadrado: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    cout << endl;
}

// ==========================================================
// EXEMPLO 5 - MULTIPLICACAO DE MATRIZES 2x2
// ==========================================================
void exemploMultiplicacaoMatrizes() {
    cout << "EXEMPLO 5: Multiplicacao de matrizes 2x2" << endl;

    int matrizA[2][2] = {
        {1, 2},
        {3, 4}
    };

    int matrizB[2][2] = {
        {5, 6},
        {7, 8}
    };

    int resultado[2][2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    cout << "Resultado da multiplicacao:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << resultado[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
}

// ==========================================================
// FUNCAO PRINCIPAL
// ==========================================================
int main() {
    exemploTabelaMultiplicacao();
    exemploMatriz3x3();
    exemploTrianguloPascal();
    exemploQuadradoAsteriscos();
    exemploMultiplicacaoMatrizes();

    return 0;
}