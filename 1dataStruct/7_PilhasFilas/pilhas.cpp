#include <iostream>
using namespace std;

const int TAMANHO = 100;
int S[TAMANHO];  // Vetor da pilha
int topo = -1;   // Pilha vazia

bool pilhaVazia() {
    return topo == -1;
}

void empilhar(int valor) {
    if (topo < TAMANHO - 1) {
        S[++topo] = valor;
        cout << "Empilhado: " << valor << endl;
    } else {
        cout << "Erro: Overflow - Pilha cheia" << endl;
    }
}

int desempilhar() {
    if (!pilhaVazia()) {
        cout << "Desempilhado: " << S[topo] << endl;
        return S[topo--];
    } else {
        cout << "Erro: Underflow - Pilha vazia" << endl;
        return -1;
    }
}

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

int main() {
    empilhar(10);
    empilhar(20);
    empilhar(30);
    mostrarPilha();
    desempilhar();
    mostrarPilha();
    return 0;
}