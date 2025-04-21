// ---------------------------------------------
// 3. Funções que Retornam Ponteiros
// ---------------------------------------------

// Em C++, não podemos retornar diretamente vetores ou matrizes por uma função,
// pois arrays não podem ser retornados por valor como variáveis comuns.

// No entanto, podemos contornar isso utilizando ponteiros. Como ponteiros
// podem armazenar o endereço de um array (ou de uma matriz), é possível
// retornar um ponteiro que aponte para uma área da memória com os dados desejados.

// EXEMPLO DE DECLARAÇÃO:
// int* calculaVetor();   -> função que retorna um ponteiro para int
// char* maiusculas();    -> função que retorna um ponteiro para char

// Ou seja, podemos retornar o endereço de um array, que estará válido
// se ele for declarado como estático dentro da função, ou alocado dinamicamente.

// ATENÇÃO:
// O array retornado não deve ser uma variável local (não estática), pois
// ele será destruído ao sair do escopo da função. Isso causará comportamento indefinido.

// Alternativas seguras:
// - Usar arrays `static` dentro da função
// - Usar `new` para alocação dinâmica e liberar depois com `delete[]`
// - Passar o array como parâmetro e modificá-lo por referência

// ---------------------------------------------
// 3.1 Ponteiros para Funções
// ---------------------------------------------

// Um ponteiro para função armazena o ENDEREÇO de uma função,
// permitindo que possamos chamá-la indiretamente ou passar como parâmetro.

// Sintaxe:
// <tipoRetorno> (*nomePonteiro)(parametros);

// Exemplo:
// int (*funcaoPonteiro)();  // ponteiro para uma função que retorna int e não recebe argumentos

#include <iostream>
using namespace std;

// Função simples
int saudacao() {
    cout << "Olá! Esta função foi chamada por meio de um ponteiro!" << endl;
    return 0;
}

// Outra função para teste
int despedida() {
    cout << "Até logo! Também fui chamada via ponteiro!" << endl;
    return 1;
}

int main() {
    // Declaração do ponteiro para função que retorna int e não recebe parâmetros
    int (*ponteiroFuncao)();

    // Atribui o endereço da função 'saudacao' ao ponteiro
    ponteiroFuncao = saudacao;

    // Chama a função através do ponteiro
    ponteiroFuncao();

    // Agora troca para apontar para a função 'despedida'
    ponteiroFuncao = despedida;
    ponteiroFuncao();  // Chamada da nova função via ponteiro

    return 0;
}

// ---------------------------------------------
// 3.2 Ponteiros para Ponteiros (int**)
// ---------------------------------------------

// Nas seções anteriores vimos que ponteiros armazenam endereços de variáveis.
// Mas também é possível que um ponteiro aponte para outro ponteiro.

// Isso é útil, por exemplo, em alocação dinâmica de matrizes,
// passagem de ponteiros por referência e manipulação de dados em níveis mais profundos.

// ✅ EXEMPLO DE DECLARAÇÃO:
// int inteiro = 512;
// int* pontInteiro = &inteiro;         // ponteiro para int
// int** pontPonteiro = &pontInteiro;   // ponteiro para ponteiro de int

// Utilizando o operador de desreferência:
// *pontInteiro   -> acessa o valor da variável 'inteiro'
// *pontPonteiro  -> acessa o valor de 'pontInteiro', ou seja, o endereço de 'inteiro'
// **pontPonteiro -> acessa o valor armazenado no endereço de 'inteiro'

#include <iostream>
using namespace std;

int main() {
    // Declaramos uma variável do tipo inteiro
    int numero = 100;

    // Declaramos um ponteiro para a variável 'numero' (ponteiro para inteiro)
    int* ponteiro = &numero;

    // Declaramos um ponteiro para o ponteiro 'ponteiro' (ponteiro para ponteiro)
    int** ponteiroParaPonteiro = &ponteiro;

    // Acessando o valor diretamente da variável 'numero'
    cout << "Valor diretamente da variável: " << numero << endl;

    // Acessando o valor através de um ponteiro
    cout << "Valor via ponteiro: " << *ponteiro << endl;

    // Acessando o valor através de um ponteiro para ponteiro
    cout << "Valor via ponteiro para ponteiro: " << **ponteiroParaPonteiro << endl;

    // Mostrando os endereços
    cout << "\nEndereços na memória:" << endl;

    // Endereço de 'numero'
    cout << "Endereço de 'numero': " << &numero << endl;

    // Endereço de 'ponteiro' (que armazena o endereço de 'numero')
    cout << "Endereço de 'ponteiro': " << ponteiro << endl;

    // Endereço de 'ponteiroParaPonteiro' (que armazena o endereço de 'ponteiro')
    cout << "Endereço de 'ponteiroParaPonteiro': " << ponteiroParaPonteiro << endl;

    return 0;
}
//Valor diretamente da variável: 100
//Valor via ponteiro: 100
//Valor via ponteiro para ponteiro: 100

//Endereços na memória:
//Endereço de 'numero': 0x7ffee2a48c1c
//Endereço de 'ponteiro': 0x7ffee2a48c1c
//Endereço de 'ponteiroParaPonteiro': 0x7ffee2a48c20
#include <iostream>
using namespace std;

int main() {
    // ---------------------------------------------
    // 4. Operadores 'new' e 'delete'
    // ---------------------------------------------

    // O operador 'new' é usado para alocar memória dinamicamente.
    // Ele retorna o endereço de memória alocado, que pode ser armazenado em um ponteiro.

    // Exemplo: Alocando um inteiro dinamicamente
    int* ponteiroInteiro = new int; // aloca espaço na memória para um inteiro

    // Atribuímos um valor a esse espaço alocado
    *ponteiroInteiro = 50;

    cout << "Valor armazenado no ponteiro: " << *ponteiroInteiro << endl;
    cout << "Endereco alocado: " << ponteiroInteiro << endl;

    // Quando a memória alocada com 'new' não é mais necessária, devemos liberá-la usando 'delete'
    delete ponteiroInteiro; // libera o espaço alocado para evitar vazamento de memória

    // ---------------------------------------------------
    // Também podemos usar 'new' para alocar vetores (arrays)
    // ---------------------------------------------------

    int tamanho = 5;

    // Alocando dinamicamente um vetor de 5 inteiros
    int* vetor = new int[tamanho];

    // Preenchendo o vetor com valores
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = (i + 1) * 10; // atribui 10, 20, 30, ...
    }

    // Exibindo os valores do vetor
    cout << "\nValores do vetor dinamicamente alocado:\n";
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Liberando a memória alocada para o vetor
    delete[] vetor; // usamos delete[] para arrays

    return 0;
}