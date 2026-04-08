// ------------------------------------------------------------
// 1. Ponteiros em C++
// ------------------------------------------------------------

/*
Um ponteiro é uma variável que armazena o endereço de memória de outra variável.

Em vez de guardar diretamente um valor, ele guarda a localização
onde esse valor está armazenado na memória.

Uma variável normalmente possui três características:
1. Nome
2. Valor
3. Endereço de memória
*/

#include <iostream>
using namespace std;

int main() {

    // ------------------------------------------------------------
    // 1.1 Declaração de Ponteiros
    // ------------------------------------------------------------

    /*
    A declaração de um ponteiro é semelhante à de uma variável comum,
    mas adicionamos o símbolo '*' para indicar que se trata de um ponteiro.

    Sintaxe geral:

        tipo* nomeDoPonteiro;

    Ponteiros podem apontar para diferentes tipos de dados
    (int, float, char, etc).
    */

    int value = 123;   // variável normal
    int* reference;    // declaração de ponteiro

    // O operador & retorna o endereço de memória da variável
    reference = &value;

    cout << "\n[Exemplo 1.1] Ponteiros - Declaração e Atribuição\n";
    cout << "Valor da variável 'value': " << value << endl;
    cout << "Endereço de memória armazenado em 'reference': " << reference << endl;


    // ------------------------------------------------------------
    // 1.2 Desreferenciação (Dereferencing)
    // ------------------------------------------------------------

    /*
    Desreferenciar um ponteiro significa acessar o valor
    que está armazenado no endereço de memória apontado por ele.

    Para isso usamos novamente o operador '*'.
    */

    int anotherValue = 21;
    int* pointer;

    // O ponteiro agora aponta para o endereço de anotherValue
    pointer = &anotherValue;

    cout << "\n[Exemplo 1.2] Desreferenciação de Ponteiro\n";

    cout << "Endereço de memória apontado por 'pointer': "
         << pointer << endl;

    cout << "Valor armazenado nesse endereço: "
         << *pointer << endl;


    // Alterando o valor usando o ponteiro
    *pointer = 12345;

    cout << "Novo valor armazenado no endereço apontado por 'pointer': "
         << *pointer << endl;


    return 0;
}