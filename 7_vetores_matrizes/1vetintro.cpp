#include <iostream>
#include <stdio.h>

using namespace std;

// Função para demonstrar o uso básico de vetores
void exemploBasicoVetores() {
    int vetor[5];  // Declara um vetor de 5 inteiros

    // Atribuindo valores ao vetor
    vetor[0] = 10;
    vetor[1] = 20;
    vetor[2] = 30;
    vetor[3] = 40;
    vetor[4] = 50;

    // Acessando e imprimindo os valores do vetor
    cout << "Valores do vetor:\n";
    for (int i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, vetor[i]);
    }
}

// Função para demonstrar o acesso a elementos de um vetor
void exemploAcessandoElementos() {
    int matriz[5] = {1, 2, 3, 4, 5};

    cout << "\nO primeiro valor da matriz é: " << matriz[0] << endl;
    cout << "O último valor da matriz é: " << matriz[4] << endl;
    cout << "Somando o segundo e o quarto elementos da matriz temos: " << matriz[1] + matriz[3] << endl;

    // Alterando o valor do terceiro elemento da matriz
    matriz[2] = 27;
    cout << "Mudamos o valor do terceiro elemento da matriz para: " << matriz[2] << endl;
}

// Função para ler e exibir elementos de um vetor
void exemploLacosParaPercorrerVetores() {
    int sequencia[4];

    // Lê os elementos do vetor a partir da entrada do usuário
    for (int i = 0; i < 4; i++) {
        cout << "Entre com o elemento número " << (i + 1) << " da sequência: ";
        cin >> sequencia[i];
    }

    // Exibe a sequência de elementos inseridos
    cout << "A sequência entrada pelo usuário foi: ";
    for (int i = 0; i < 4; i++) {
        cout << sequencia[i] << " ";
    }
    cout << endl;
}

// Função para usar constantes no tamanho do vetor
void exemploUsandoConstantes() {
    const int TAMANHO = 4;       // Define uma constante para o tamanho do array
    int sequencia[TAMANHO];      // Declara o array com tamanho fixo usando a constante

    // Lê os elementos do array a partir da entrada do usuário
    for (int i = 0; i < TAMANHO; i++) {
        cout << "Entre com o elemento número " << (i + 1) << " da sequência: ";
        cin >> sequencia[i];
    }

    // Exibe a sequência de elementos inseridos
    cout << "A sequência entrada pelo usuário foi: ";
    for (int i = 0; i < TAMANHO; i++) {
        cout << sequencia[i] << " ";
    }
    cout << endl;
}

// Função principal
int main() {
    // Chama as funções para demonstrar o uso de vetores
    exemploBasicoVetores();
    exemploAcessandoElementos();
    exemploLacosParaPercorrerVetores();
    exemploUsandoConstantes();

    return 0; // Finaliza o programa
}