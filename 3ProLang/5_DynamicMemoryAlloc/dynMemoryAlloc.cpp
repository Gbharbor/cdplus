#include <iostream>
#include <new>        // new e delete

using namespace std;

int globalVar = 10;  // Variável global, acessível em qualquer parte do código

// Função que demonstra o uso de variáveis locais
void showScopeExample() {
    int localVar = 5;  // Variável local, só acessível dentro da função showScopeExample
    cout << "[Escopo] Variável local: " << localVar << endl;
}

int main() {
    // ---------- 1. Escopo de Variáveis ----------
    cout << "=== 1. Escopo de Variáveis ===" << endl;
    cout << "[Escopo] Exibe a var global: " << globalVar << endl;
    showScopeExample();  // Exibe a variável local da função showScopeExample

    // ---------- 2. Alocação Dinâmica com Tamanho Definido pelo Usuário ----------
    cout << "\n=== 2. Alocação Dinâmica com Tamanho Definido pelo Usuário ===" << endl;
    int size;  // Declara uma variável para armazenar o tamanho do array
    cout << "Digite o número de elementos: ";
    cin >> size;  // Lê o tamanho do array a ser alocado

    // Aloca dinamicamente um array de inteiros no heap
    int* vector = new int[size];  // O ponteiro vector agora aponta para a memória alocada no heap. int[size] indica um array com 'size' elementos.
    // Exemplo: Se o usuário digitou 5, o vetor será alocado com 5 elementos:
    // [ 0 ] [ 0 ] [ 0 ] [ 0 ] [ 0 ]
    //       ↑
    //      vector

    // Preenche e exibe os valores do vetor
    for (int i = 0; i < size; i++) {
        vector[i] = i * 10;  // Preenche o vetor com múltiplos de 10
        cout << vector[i] << " ";  // Exibe cada valor
    }
    cout << endl;  // Pula uma linha para separar a saída

    // Libera a memória alocada para o vetor
    delete[] vector;  // Libera a memória do array alocado dinamicamente

    // ---------- 3. Estática vs Dinâmica ----------
    cout << "\n=== 3. Estática vs Dinâmica ===" << endl;
    int staticVar = 100;  // Variável alocada automaticamente na pilha (stack)
    int* dynamicVar = new int(200);  // Variável alocada dinamicamente no heap com valor inicial 200

    // Exibe os valores das variáveis estáticas e dinâmicas
    cout << "[Estática] Valor: " << staticVar << endl;
    cout << "[Dinâmica] Valor: " << *dynamicVar << endl;

    // Libera a memória alocada dinamicamente para dynamicVar
    delete dynamicVar;  // Libera a memória do inteiro alocado dinamicamente

    // ---------- 4. Operadores new/delete ----------
    cout << "\n=== 4. Operadores new/delete ===" << endl;
    int* number = new int(42);  // Aloca dinamicamente um inteiro com valor 42
    cout << "Valor alocado com new: " << *number << endl;  // Exibe o valor alocado
    delete number;  // Libera a memória alocada para 'number'

    // ---------- 5. Alocação de Array com new[] ----------
    cout << "\n=== 5. Alocação de Array com new[] ===" << endl;
    int* array = new int[5];  // Aloca dinamicamente um array de 5 inteiros
    for (int i = 0; i < 5; i++) {
        array[i] = i + 1;  // Preenche o array com os valores 1, 2, 3, 4, 5
        cout << array[i] << " ";  // Exibe os valores do array
    }
    cout << endl;  // Pula uma linha

    // Libera a memória alocada para o array
    delete[] array;  // Libera a memória do array alocado dinamicamente

    // ---------- 6. Esgotamento de Memória (simulado) ----------
    cout << "\n=== 6. Esgotamento de Memória (simulado) ===" << endl;
    long long bigSize = 1e12;  // Tamanho muito grande para alocar (simulação de erro)

    // Tenta alocar uma grande quantidade de memória
    int* pointer = new(nothrow) int[bigSize];  // Usando "nothrow" para evitar exceções em caso de erro de alocação
   /*
   Normalmente, se a alocação falha (por exemplo, se você pedir memória demais), o 'new' lança uma exceção (std::bad_alloc), e isso pode travar o programa se você não tratar.
   Com o "new(nothrow)", o que acontece é que, se não conseguir alocar memória, em vez de lançar uma exceção, o ponteiro será configurado como nullptr.
   Ou seja, em vez de gerar um erro fatal, o programa continua e você pode tratar o erro de maneira mais segura.
   */
    if (!pointer) {  // Verifica se a alocação falhou (ponteiro será nullptr)
        cout << "[Erro] Falha na alocação de memória!" << endl;  // Exibe uma mensagem de erro
    } else {
        cout << "[OK] Memória alocada com sucesso." << endl;  // Caso contrário, confirma que a alocação foi bem-sucedida
        delete[] pointer;  // Libera a memória alocada
    }

    return 0;
}