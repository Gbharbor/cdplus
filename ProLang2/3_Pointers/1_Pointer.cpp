// ---------------------------------------------
// 1. Ponteiros em C++
// ---------------------------------------------

// Um ponteiro é uma variável que armazena o endereço de memória de outra variável.
// Em vez de armazenar um valor diretamente, ele aponta para a localização desse valor na memória.

// ---------------------------------------------
// 1.1 Declarando Ponteiros
// ---------------------------------------------

// A declaração de um ponteiro é semelhante à de uma variável comum, 
// com a adição do asterisco (*) para indicar que é um ponteiro.
// A sintaxe é: <tipo>* <nomeDoPonteiro>;
// Os ponteiros podem ser de vários tipos, inclusive do tipo void (ponteiro genérico).

#include <iostream>
using namespace std;

int main() {
    int valor = 123;
    int* referencia; // Declaração do ponteiro

    // Atribuindo o endereço de 'valor' ao ponteiro 'referencia'
    referencia = &valor;

    cout << "\n[Exemplo 1.1] Ponteiros - Declarando e Atribuindo\n";
    cout << "Valor da variável 'valor': " << valor << endl;
    cout << "Endereço de memória armazenado em 'referencia': " << referencia << endl;

    // ---------------------------------------------
    // 1.2 Desreferenciando um Ponteiro
    // ---------------------------------------------

    // Desreferenciar um ponteiro significa acessar o valor armazenado no endereço de memória 
    // para o qual o ponteiro aponta. Isso é feito usando o operador * (asterisco de indireção).

    int outroValor = 21;
    int* ponteiro;

    ponteiro = &outroValor; // 'ponteiro' aponta para o endereço de 'outroValor'

    cout << "\n[Exemplo 1.2] Desreferenciando um Ponteiro\n";
    cout << "Endereço de memória apontado por 'ponteiro': " << ponteiro << endl;
    cout << "Valor armazenado no endereço apontado por 'ponteiro': " << *ponteiro << endl;

    // Modificando o valor no endereço apontado por 'ponteiro'
    *ponteiro = 12345;

    cout << "Novo valor armazenado no endereço apontado por 'ponteiro': " << *ponteiro << endl;

    return 0;
}