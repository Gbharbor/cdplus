#include <iostream>
using namespace std;

// ------------------------------------------------------
// PILHA (STACK) IMPLEMENTADA COM VETOR
// ------------------------------------------------------

const int TAMANHO = 100;

int S[TAMANHO];   // vetor que armazena a pilha
int topo = -1;    // topo da pilha (-1 indica pilha vazia)


// ------------------------------------------------------
// Verifica se a pilha está vazia
// ------------------------------------------------------
bool pilhaVazia() {
    return topo == -1;
}


// ------------------------------------------------------
// EMPILHAR (push)
// Insere um elemento no topo da pilha
// ------------------------------------------------------
void empilhar(int valor) {

    if (topo < TAMANHO - 1) {

        S[++topo] = valor;  // incrementa topo e insere valor

        cout << "Empilhado: " << valor << endl;

    } else {

        cout << "Erro: Overflow - Pilha cheia" << endl;

    }
}


// ------------------------------------------------------
// DESEMPILHAR (pop)
// Remove o elemento do topo
// ------------------------------------------------------
int desempilhar() {

    if (!pilhaVazia()) {

        cout << "Desempilhado: " << S[topo] << endl;

        return S[topo--];   // retorna o valor e reduz o topo

    } else {

        cout << "Erro: Underflow - Pilha vazia" << endl;

        return -1;
    }
}


// ------------------------------------------------------
// MOSTRAR PILHA
// ------------------------------------------------------
void mostrarPilha() {

    if (pilhaVazia()) {

        cout << "Pilha vazia." << endl;

        return;
    }

    cout << "Pilha: ";

    for (int i = 0; i <= topo; i++) {

        cout << S[i] << " ";

    }

    cout << endl;
}


// ------------------------------------------------------
// MAIN
// ------------------------------------------------------
int main() {

    empilhar(10);
    empilhar(20);
    empilhar(30);

    mostrarPilha();

    desempilhar();

    mostrarPilha();

    return 0;
}