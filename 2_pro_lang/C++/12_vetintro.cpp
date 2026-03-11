#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Exemplo 1: declaração, atribuição e impressão de vetores
// ------------------------------------------------------------
void exemploBasicoVetores() {
    int vetor[5]; // Vetor com 5 posições inteiras

    vetor[0] = 10;
    vetor[1] = 20;
    vetor[2] = 30;
    vetor[3] = 40;
    vetor[4] = 50;

    cout << "Valores armazenados no vetor:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Elemento " << i << ": " << vetor[i] << endl;
    }
}

// ------------------------------------------------------------
// Exemplo 2: acesso e alteração de elementos do vetor
// ------------------------------------------------------------
void exemploAcessandoElementos() {
    int vetor[5] = {1, 2, 3, 4, 5};

    cout << "\nAcessando elementos do vetor:\n";
    cout << "Primeiro elemento: " << vetor[0] << endl;
    cout << "Último elemento: " << vetor[4] << endl;
    cout << "Soma do segundo com o quarto elemento: " << vetor[1] + vetor[3] << endl;

    // Alterando o valor do terceiro elemento
    vetor[2] = 27;
    cout << "O terceiro elemento foi alterado para: " << vetor[2] << endl;
}

// ------------------------------------------------------------
// Exemplo 3: leitura e exibição de um vetor com laços
// ------------------------------------------------------------
void exemploLacosParaPercorrerVetores() {
    int sequencia[4];

    cout << "\nLeitura de valores para o vetor:\n";

    // Lê os elementos do vetor a partir da entrada do utilizador
    for (int i = 0; i < 4; i++) {
        cout << "Entre com o elemento numero " << (i + 1) << " da sequencia: ";
        cin >> sequencia[i];
    }

    // Exibe os elementos inseridos
    cout << "A sequencia introduzida pelo utilizador foi: ";
    for (int i = 0; i < 4; i++) {
        cout << sequencia[i] << " ";
    }
    cout << endl;
}

// ------------------------------------------------------------
// Exemplo 4: uso de constante para definir o tamanho do vetor
// ------------------------------------------------------------
void exemploUsandoConstantes() {
    const int TAMANHO = 4;      // Constante para definir o tamanho do vetor
    int sequencia[TAMANHO];     // Vetor com tamanho fixo definido pela constante

    cout << "\nLeitura de valores usando constante para o tamanho do vetor:\n";

    // Lê os elementos do vetor
    for (int i = 0; i < TAMANHO; i++) {
        cout << "Entre com o elemento numero " << (i + 1) << " da sequencia: ";
        cin >> sequencia[i];
    }

    // Exibe os elementos inseridos
    cout << "A sequencia introduzida pelo utilizador foi: ";
    for (int i = 0; i < TAMANHO; i++) {
        cout << sequencia[i] << " ";
    }
    cout << endl;
}

// ------------------------------------------------------------
// Função principal
// ------------------------------------------------------------
int main() {
    exemploBasicoVetores();
    exemploAcessandoElementos();
    exemploLacosParaPercorrerVetores();
    exemploUsandoConstantes();

    return 0;
}