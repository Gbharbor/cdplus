// ===============================================================
// PONTEIROS: RETORNO DE PONTEIROS, PONTEIROS PARA FUNÇÕES,
// PONTEIROS PARA PONTEIROS E ALOCAÇÃO DINÂMICA
// ===============================================================

#include <iostream>
using namespace std;

// ---------------------------------------------------------------
// 3. FUNÇÕES QUE RETORNAM PONTEIROS
// ---------------------------------------------------------------

/*
Em C++, não podemos retornar arrays ou matrizes diretamente por valor
da mesma forma que retornamos variáveis simples.

No entanto, podemos retornar ponteiros, ou seja, endereços de memória
que apontam para os dados desejados.

Exemplos de declaração:
   int* calcularArray();   -> função que retorna ponteiro para int
   char* maiusculas();     -> função que retorna ponteiro para char

IMPORTANTE:
Não devemos retornar o endereço de uma variável local comum,
porque ela deixa de existir ao terminar a função.

Alternativas seguras:
- usar arrays estáticos dentro da função
- usar alocação dinâmica com new e liberar depois com delete[]
- passar o array como parâmetro e modificá-lo por referência
*/


// ---------------------------------------------------------------
// 3.1 PONTEIROS PARA FUNÇÕES
// ---------------------------------------------------------------

/*
Um ponteiro para função armazena o endereço de uma função.

Isso permite:
- chamar a função indiretamente
- passar funções como parâmetro
- trocar dinamicamente qual função será executada

Sintaxe geral:
   tipoRetorno (*nomePonteiro)(parâmetros);
*/

// Função simples
int greeting() {
    cout << "Olá! Esta função foi chamada através de um ponteiro!" << endl;
    return 0;
}

// Outra função para teste
int farewell() {
    cout << "Tchau! Eu também fui chamada através de um ponteiro!" << endl;
    return 1;
}

void exemploPonteiroParaFuncao() {
    cout << "\n=== Exemplo 3.1: Ponteiros para Funções ===" << endl;

    // Ponteiro para função que retorna int e não recebe parâmetros
    int (*functionPointer)();

    // Guarda o endereço da função greeting
    functionPointer = greeting;
    functionPointer();

    // Agora aponta para a função farewell
    functionPointer = farewell;
    functionPointer();
}


// ---------------------------------------------------------------
// 3.2 PONTEIROS PARA PONTEIROS (int**)
// ---------------------------------------------------------------

/*
Se um ponteiro guarda o endereço de uma variável,
então também é possível ter um ponteiro que guarda
o endereço de outro ponteiro.

Exemplo:
   int number = 512;
   int* pointerToInt = &number;
   int** pointerToPointer = &pointerToInt;

Interpretação:
   *pointerToInt        -> valor de number
   *pointerToPointer    -> valor de pointerToInt (endereço de number)
   **pointerToPointer   -> valor armazenado em number
*/

void exemploPonteiroParaPonteiro() {
    cout << "\n=== Exemplo 3.2: Ponteiros para Ponteiros ===" << endl;

    int number = 100;
    int* pointer = &number;
    int** pointerToPointer = &pointer;

    cout << "Valor diretamente pela variável: " << number << endl;
    cout << "Valor através do ponteiro: " << *pointer << endl;
    cout << "Valor através do ponteiro para ponteiro: " << **pointerToPointer << endl;

    cout << "\nEndereços de memória:" << endl;
    cout << "Endereço de 'number': " << &number << endl;
    cout << "Valor armazenado em 'pointer' (endereço de number): " << pointer << endl;
    cout << "Valor armazenado em 'pointerToPointer' (endereço de pointer): "
         << pointerToPointer << endl;
}


// ---------------------------------------------------------------
// 3.3 OPERADORES new E delete
// ---------------------------------------------------------------

/*
O operador new é usado para alocar memória dinamicamente.
Ele devolve o endereço da memória alocada, que normalmente
é armazenado em um ponteiro.

Quando essa memória não for mais necessária,
deve ser liberada com delete ou delete[].
*/

void exemploNewDelete() {
    cout << "\n=== Exemplo 3.3: Operadores new e delete ===" << endl;

    // Alocação dinâmica de um inteiro
    int* pointerToInteger = new int;

    *pointerToInteger = 50;

    cout << "Valor armazenado no ponteiro: " << *pointerToInteger << endl;
    cout << "Endereço alocado: " << pointerToInteger << endl;

    // Liberação da memória do inteiro
    delete pointerToInteger;


    // -----------------------------------------------------------
    // Alocação dinâmica de arrays
    // -----------------------------------------------------------

    int size = 5;

    // Aloca dinamicamente um array de 5 inteiros
    int* array = new int[size];

    // Preenche o array
    for (int i = 0; i < size; i++) {
        array[i] = (i + 1) * 10;
    }

    // Exibe os valores
    cout << "\nValores do array alocado dinamicamente:" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Libera a memória do array
    delete[] array;
}


// ---------------------------------------------------------------
// FUNÇÃO PRINCIPAL
// ---------------------------------------------------------------

int main() {
    exemploPonteiroParaFuncao();
    exemploPonteiroParaPonteiro();
    exemploNewDelete();

    return 0;
}