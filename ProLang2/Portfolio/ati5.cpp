/*
Crie um programa em C++ que leia um valor n e crie dinamicamente um vetor de n elementos e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no programa principal, o vetor preenchido deve ser impresso. Antes de finalizar o programa o programa deve liberar a área de memória alocada. 
*/
#include <iostream>           // Biblioteca padrão para entrada e saída (cin, cout)
using namespace std;          // Permite usar cout e cin sem o prefixo std::

/*
 Função que preenche o vetor com valores fornecidos pelo usuário
 Parâmetros:
   - arr: ponteiro para o vetor alocado dinamicamente
   - size: tamanho do vetor
*/
void fillArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {                 // Loop de 0 até size - 1
        cout << "Elemento [" << i << "]: ";          // Pede o valor para a posição i
        cin >> arr[i];                               // Lê e armazena o valor digitado no vetor
    }
}

/*
 Função que imprime os valores do vetor na tela
 Parâmetros:
   - arr: ponteiro para o vetor
   - size: tamanho do vetor
*/
void printArray(const int* arr, int size) {
    cout << "\nVetor preenchido:\n";                 // Mensagem de início da impressão
    for (int i = 0; i < size; ++i) {                 // Loop para percorrer o vetor
        cout << arr[i] << " ";                       // Imprime o valor da posição i
    }
    cout << endl;                                    // Quebra de linha após o vetor
}

int main() {
    int n;                                           // Variável para armazenar o tamanho do vetor
    cout << "Tamanho do vetor: ";                    // Solicita o tamanho ao usuário
    cin >> n;                                        // Lê o tamanho digitado

    // Alocação dinâmica do vetor com n posições, usando nothrow para evitar exceção
    int* array = new(nothrow) int[n];                

    // Verifica se a alocação falhou (array == nullptr)
    if (!array) {
        cerr << "Erro: Falha na alocação de memória.\n"; // Mensagem de erro se falhar
        return 1;                                         // Encerra o programa com erro
    }

    fillArray(array, n);                             // Chama a função para preencher o vetor
    printArray(array, n);                            // Chama a função para imprimir o vetor

    delete[] array;                                  // Libera a memória alocada para evitar vazamento
    return 0;                                        // Encerra o programa com sucesso
}