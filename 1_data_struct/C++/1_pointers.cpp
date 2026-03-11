#include <iostream>
using namespace std;


// ======================================================
// FUNCAO QUE TROCA VALORES USANDO PONTEIROS
// ======================================================
// Recebe os ENDERECOS de duas variaveis.
// Assim conseguimos modificar os valores originais.
void troca_ponteiro(int *n1, int *n2) {

    int aux = *n1; // guarda o valor apontado por n1
    *n1 = *n2;     // copia valor de n2 para n1
    *n2 = aux;     // coloca valor antigo de n1 em n2
}


int main() {

    // ======================================================
    // PARTE 1 - ENDERECO DE MEMORIA
    // ======================================================

    int valor = 10;

    // O operador & retorna o endereco da variavel na memoria
    cout << "Endereco da variavel valor: " << &valor << endl;



    // ======================================================
    // PARTE 2 - DECLARACAO E USO DE PONTEIRO
    // ======================================================

    // Ponteiro para inteiro
    // Inicializado com nullptr (boa pratica em C++)
    int *ptr = nullptr;

    // Agora o ponteiro passa a apontar para "valor"
    ptr = &valor;

    // O operador * acessa o VALOR armazenado no endereco apontado
    cout << "Valor acessado por ponteiro: " << *ptr << endl;



    // ======================================================
    // PARTE 3 - MODIFICANDO VALOR VIA PONTEIRO
    // ======================================================

    // Alterando o valor da variavel atraves do ponteiro
    *ptr = 20;

    cout << "Novo valor da variavel valor (modificado via ponteiro): "
         << valor << endl;



    // ======================================================
    // PARTE 4 - ALOCACAO DINAMICA DE MEMORIA
    // ======================================================

    // new reserva memoria dinamicamente no heap
    int *dinamico = new int;

    *dinamico = 50;

    cout << "Valor alocado dinamicamente: " << *dinamico << endl;

    // delete libera a memoria que foi alocada com new
    delete dinamico;



    // ======================================================
    // PARTE 5 - PONTEIROS EM FUNCOES
    // ======================================================

    int a = 5, b = 8;

    cout << "Antes da troca: a = " << a << ", b = " << b << endl;

    // Passamos os ENDERECOS das variaveis
    troca_ponteiro(&a, &b);

    cout << "Depois da troca usando ponteiros: a = "
         << a << ", b = " << b << endl;


    return 0;
}