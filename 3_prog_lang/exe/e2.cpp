#include <iostream>
using namespace std;

// Função que encontra o maior valor no array e armazena na variável 'largest'
void findLargest(int array[], int size, int &largest) {
    // Loop que percorre todos os elementos do array a partir do segundo (i = 1)
    for (int i = 1; i < size; ++i) {
        // Se o valor atual (array[i]) for maior que o valor armazenado em 'largest',
        // atualiza 'largest' com o novo valor encontrado.
        if (array[i] > largest) 
            largest = array[i];
    }
}

int main() {
    // Declaração e inicialização do array com alguns números
    int array[] = {3, 7, 1, 9, 4, 2};

    // Cálculo do tamanho do array usando sizeof:
    // O tamanho total do array é dividido pelo tamanho de um único elemento
    // Isso retorna o número de elementos do array.
    int size = sizeof(array) / sizeof(array[0]); 
    
    // Inicializa a variável 'largestValue' com o primeiro valor do array (array[0])
    // Essa variável será usada para armazenar o maior valor encontrado no array.
    int largestValue = array[0];

    // Chama a função findLargest passando o array, seu tamanho e a variável 'largestValue'
    // Essa função vai percorrer o array e atualizar 'largestValue' com o maior valor encontrado.
    findLargest(array, size, largestValue); 

    // Exibe o maior valor encontrado no array
    // O valor é impresso no console com a mensagem "o maior valor é: ".
    cout << "o maior valor é: " << largestValue << endl;

    // Retorna 0 para indicar que o programa terminou corretamente
    return 0;
}