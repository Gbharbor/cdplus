#include <iostream>
#include <new>   // Para new, delete e nothrow

using namespace std;

// ------------------------------------------------------------
// Variável global
// ------------------------------------------------------------
// Pode ser acessada em qualquer parte do programa
int globalVar = 10;


// ------------------------------------------------------------
// Função que demonstra o uso de variável local
// ------------------------------------------------------------
void showScopeExample() {
    int localVar = 5;  // Variável local: existe apenas dentro desta função
    cout << "[Escopo] Variavel local: " << localVar << endl;
}


int main() {

    // --------------------------------------------------------
    // 1. Escopo de variáveis
    // --------------------------------------------------------
    cout << "=== 1. Escopo de Variaveis ===" << endl;

    cout << "[Escopo] Variavel global: " << globalVar << endl;

    showScopeExample();


    // --------------------------------------------------------
    // 2. Alocação dinâmica com tamanho definido pelo utilizador
    // --------------------------------------------------------
    cout << "\n=== 2. Alocacao Dinamica com Tamanho Definido pelo Utilizador ===" << endl;

    int size;

    cout << "Digite o numero de elementos: ";
    cin >> size;

    /*
       Aloca dinamicamente um vetor de inteiros no heap.
       O ponteiro 'vector' passa a apontar para o primeiro
       elemento da memória alocada.
    */
    int* vector = new int[size];

    // Preenche e exibe os valores do vetor
    for (int i = 0; i < size; i++) {
        vector[i] = i * 10;
        cout << vector[i] << " ";
    }
    cout << endl;

    // Liberta a memória alocada dinamicamente
    delete[] vector;


    // --------------------------------------------------------
    // 3. Variável estática (automática) vs dinâmica
    // --------------------------------------------------------
    cout << "\n=== 3. Estatica vs Dinamica ===" << endl;

    int staticVar = 100;          // armazenada automaticamente
    int* dynamicVar = new int(200); // armazenada dinamicamente no heap

    cout << "[Estatica] Valor: " << staticVar << endl;
    cout << "[Dinamica] Valor: " << *dynamicVar << endl;

    delete dynamicVar;


    // --------------------------------------------------------
    // 4. Operadores new e delete
    // --------------------------------------------------------
    cout << "\n=== 4. Operadores new e delete ===" << endl;

    int* number = new int(42);

    cout << "Valor alocado com new: " << *number << endl;

    delete number;


    // --------------------------------------------------------
    // 5. Alocação de array com new[]
    // --------------------------------------------------------
    cout << "\n=== 5. Alocacao de Array com new[] ===" << endl;

    int* array = new int[5];

    for (int i = 0; i < 5; i++) {
        array[i] = i + 1;
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;


    // --------------------------------------------------------
    // 6. Esgotamento de memória (simulado)
    // --------------------------------------------------------
    cout << "\n=== 6. Esgotamento de Memoria (simulado) ===" << endl;

    long long bigSize = 1e12; // valor muito grande para simular falha de alocação

    /*
       Normalmente, se a alocação falha, o operador new lança
       uma exceção do tipo std::bad_alloc.

       Com new(nothrow), em vez de lançar exceção, o ponteiro
       recebe nullptr, permitindo tratar o erro manualmente.
    */
    int* pointer = new(nothrow) int[bigSize];

    if (!pointer) {
        cout << "[Erro] Falha na alocacao de memoria!" << endl;
    } else {
        cout << "[OK] Memoria alocada com sucesso." << endl;
        delete[] pointer;
    }

    return 0;
}