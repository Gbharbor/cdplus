/*
Faça um programa na linguagem C/C++ que implemente uma Lista por meio de um vetor de inteiros, de tamanho n, alocado dinamicamente. A implementação deverá contemplar as operações de busca, inserção e remoção de elementos na lista. Para isso, o programa deverá apresentar um menu para que o usuário possa escolher a operação desejada. Após cada operação realizada a Lista deverá ser apresentada na tela.
*/
#include <iostream>
using namespace std;

// Função para mostrar os elementos da lista
void mostrarLista(int* lista, int tamanho) {
    cout << "Lista: ";
    for (int i = 0; i < tamanho; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
}

// Inserção de elemento no final da lista
void inserirElemento(int*& lista, int& tamanho, int valor) {
    // Cria novo vetor com tamanho + 1
    int* novaLista = new int[tamanho + 1];

    // Copia os elementos antigos
    for (int i = 0; i < tamanho; i++) {
        novaLista[i] = lista[i];
    }

    // Adiciona novo valor
    novaLista[tamanho] = valor;

    // Libera memória antiga e atualiza ponteiro
    delete[] lista;
    lista = novaLista;
    tamanho++;
}

// Remoção de um elemento (a primeira ocorrência)
void removerElemento(int*& lista, int& tamanho, int valor) {
    int pos = -1;

    // Busca o valor na lista
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == valor) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Valor nao encontrado." << endl;
        return;
    }

    // Cria novo vetor com tamanho - 1
    int* novaLista = new int[tamanho - 1];

    // Copia todos os elementos, exceto o removido
    for (int i = 0, j = 0; i < tamanho; i++) {
        if (i != pos) {
            novaLista[j++] = lista[i];
        }
    }

    // Libera memória antiga e atualiza ponteiro
    delete[] lista;
    lista = novaLista;
    tamanho--;

    cout << "Valor removido com sucesso." << endl;
}

// Busca por um elemento
void buscarElemento(int* lista, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == valor) {
            cout << "Valor encontrado na posicao " << i << "." << endl;
            return;
        }
    }
    cout << "Valor nao encontrado na lista." << endl;
}

int main() {
    int* lista = nullptr;
    int tamanho = 0;
    int opcao, valor;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Inserir elemento" << endl;
        cout << "2. Remover elemento" << endl;
        cout << "3. Buscar elemento" << endl;
        cout << "4. Mostrar lista" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Informe o valor a inserir: ";
                cin >> valor;
                inserirElemento(lista, tamanho, valor);
                mostrarLista(lista, tamanho);
                break;

            case 2:
                cout << "Informe o valor a remover: ";
                cin >> valor;
                removerElemento(lista, tamanho, valor);
                mostrarLista(lista, tamanho);
                break;

            case 3:
                cout << "Informe o valor a buscar: ";
                cin >> valor;
                buscarElemento(lista, tamanho, valor);
                break;

            case 4:
                mostrarLista(lista, tamanho);
                break;

            case 0:
                cout << "Encerrando o programa..." << endl;
                break;

            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);

    // Libera memória final
    delete[] lista;
    return 0;
}