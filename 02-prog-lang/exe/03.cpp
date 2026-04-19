#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int matriz[N][N];
    int numero;

    // Leitura da matriz 10x10
    cout << "Digite os elementos da matriz 10x10:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Solicita um número ao usuário
    cout << "Digite um numero: ";
    cin >> numero;

    // Multiplicação dos elementos da diagonal primária pelo número
    for (int i = 0; i < N; i++) {
        matriz[i][i] *= numero;
    }

    // Multiplicação dos elementos da diagonal secundária pelo dobro do número
    for (int i = 0; i < N; i++) {
        matriz[i][N - i - 1] *= (2 * numero);
    }

    // Exibição da matriz resultante
    cout << "\nMatriz resultante:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}