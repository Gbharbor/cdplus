#include <iostream>
using namespace std;

const int TAM = 100;
int Q[TAM];         // Vetor da fila
int inicio = 0;
int fim = 0;

bool filaVazia() {
    return inicio == fim;
}

bool filaCheia() {
    return (fim + 1) % TAM == inicio;
}

void enfileirar(int valor) {
    if (!filaCheia()) {
        Q[fim] = valor;
        fim = (fim + 1) % TAM;
        cout << "Enfileirado: " << valor << endl;
    } else {
        cout << "Erro: Overflow - Fila cheia" << endl;
    }
}

int desenfileirar() {
    if (!filaVazia()) {
        int valor = Q[inicio];
        inicio = (inicio + 1) % TAM;
        cout << "Desenfileirado: " << valor << endl;
        return valor;
    } else {
        cout << "Erro: Underflow - Fila vazia" << endl;
        return -1;
    }
}

void mostrarFila() {
    if (filaVazia()) {
        cout << "Fila vazia." << endl;
        return;
    }
    cout << "Fila: ";
    int i = inicio;
    while (i != fim) {
        cout << Q[i] << " ";
        i = (i + 1) % TAM;
    }
    cout << endl;
}

int main() {
    enfileirar(5);
    enfileirar(15);
    enfileirar(25);
    mostrarFila();
    desenfileirar();
    mostrarFila();
    return 0;
}