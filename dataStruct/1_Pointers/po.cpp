#include <iostream>
using namespace std;

// Função que troca os valores de duas variáveis usando ponteiros
void troca_ponteiro(int *n1, int *n2) {
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

int main() {
    // Parte 1: Endereço de memória
    int valor = 10;
    cout << "Endereco da variavel valor: " << &valor << endl;

    // Parte 2: Declaração e atribuição de ponteiro
    int *ptr = nullptr; // Inicialmente nulo
    ptr = &valor;       // Apontando para a variável valor
    cout << "Valor acessado por ponteiro: " << *ptr << endl;

    // Parte 3: Modificando valor via ponteiro
    *ptr = 20;
    cout << "Novo valor da variavel valor (modificado via ponteiro): " << valor << endl;

    // Parte 4: Alocação dinâmica
    int *dinamico = new int; // Novo espaço de memória
    *dinamico = 50;
    cout << "Valor alocado dinamicamente: " << *dinamico << endl;

    // Desalocando memória
    delete dinamico;

    // Parte 5: Ponteiro em função
    int a = 5, b = 8;
    cout << "Antes da troca: a = " << a << ", b = " << b << endl;
    troca_ponteiro(&a, &b);
    cout << "Depois da troca usando ponteiros: a = " << a << ", b = " << b << endl;

    return 0;
}
