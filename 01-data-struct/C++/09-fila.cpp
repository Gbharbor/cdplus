#include <iostream>
using namespace std;

// ------------------------------------------------------
// FILA CIRCULAR IMPLEMENTADA COM VETOR
// ------------------------------------------------------

const int TAM = 100;

int Q[TAM];   // vetor que armazena a fila
int inicio = 0;  // aponta para o primeiro elemento
int fim = 0;     // aponta para a próxima posição livre


// ------------------------------------------------------
// Verifica se a fila está vazia
// ------------------------------------------------------
bool filaVazia() {
    return inicio == fim;
}


// ------------------------------------------------------
// Verifica se a fila está cheia
// (condição típica de fila circular)
// ------------------------------------------------------
bool filaCheia() {
    return (fim + 1) % TAM == inicio;
}


// ------------------------------------------------------
// ENFILEIRAR (inserir elemento na fila)
// ------------------------------------------------------
void enfileirar(int valor) {

    if (!filaCheia()) {

        Q[fim] = valor;

        // avanço circular
        fim = (fim + 1) % TAM;

        cout << "Enfileirado: " << valor << endl;

    } else {

        cout << "Erro: Overflow - Fila cheia" << endl;

    }
}


// ------------------------------------------------------
// DESENFILEIRAR (remover elemento da fila)
// ------------------------------------------------------
int desenfileirar() {

    if (!filaVazia()) {

        int valor = Q[inicio];

        // avanço circular
        inicio = (inicio + 1) % TAM;

        cout << "Desenfileirado: " << valor << endl;

        return valor;

    } else {

        cout << "Erro: Underflow - Fila vazia" << endl;

        return -1;
    }
}


// ------------------------------------------------------
// MOSTRAR FILA
// ------------------------------------------------------
void mostrarFila() {

    if (filaVazia()) {
        cout << "Fila vazia." << endl;
        return;
    }

    cout << "Fila: ";

    int i = inicio;

    // percorre circularmente até chegar ao fim
    while (i != fim) {

        cout << Q[i] << " ";

        i = (i + 1) % TAM;
    }

    cout << endl;
}


// ------------------------------------------------------
// MAIN
// ------------------------------------------------------
int main() {

    enfileirar(5);
    enfileirar(15);
    enfileirar(25);

    mostrarFila();

    desenfileirar();

    mostrarFila();

    return 0;
}