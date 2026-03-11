#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Exemplo 1: vetor de inteiros
// ------------------------------------------------------------
void exemploVetorInteiros() {

    // Declaração e inicialização de um vetor de inteiros
    int notas[5] = {10, 9, 8, 7, 6};

    cout << "Notas dos alunos:" << endl;

    // Percorre e exibe os elementos do vetor
    for (int i = 0; i < 5; i++) {
        cout << "Nota " << i + 1 << ": " << notas[i] << endl;
    }

    cout << endl;
}

// ------------------------------------------------------------
// Exemplo 2: vetor de caracteres
// ------------------------------------------------------------
void exemploVetorCaracteres() {

    // Declaração e inicialização de um vetor de caracteres
    char iniciais[5] = {'A', 'B', 'C', 'D', 'E'};

    cout << "Iniciais:" << endl;

    // Percorre e exibe os elementos do vetor
    for (int i = 0; i < 5; i++) {
        cout << "Inicial " << i + 1 << ": " << iniciais[i] << endl;
    }

    cout << endl;
}

// ------------------------------------------------------------
// Exemplo 3: vetor de números float
// ------------------------------------------------------------
void exemploVetorFloat() {

    // Declaração e inicialização de um vetor de números reais
    float medias[4] = {7.5, 8.2, 6.3, 9.1};

    cout << "Medias dos alunos:" << endl;

    // Percorre e exibe os elementos do vetor
    for (int i = 0; i < 4; i++) {
        cout << "Media " << i + 1 << ": " << medias[i] << endl;
    }

    cout << endl;
}

// ------------------------------------------------------------
// Função principal
// ------------------------------------------------------------
int main() {

    exemploVetorInteiros();
    exemploVetorCaracteres();
    exemploVetorFloat();

    return 0;
}