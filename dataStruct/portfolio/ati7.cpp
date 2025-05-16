/*
Faça um programa na linguagem C/C++ que implemente uma Pilha por meio de um vetor de inteiros, de tamanho n, alocado dinamicamente. A implementação deverá contemplar as operações de inserção e remoção de elementos na Pilha. Para isso, o programa deverá apresentar um menu para que o usuário possa escolher a operação desejada. Após cada operação realizada a Pilha deverá ser apresentada na tela.
*/
#include <iostream>
using namespace std;

// Função para mostrar a pilha (do topo até o início)
void mostrarPilha(int* pilha, int topo) {
    cout << "Pilha: ";
    if (topo == -1) {
        cout << "[vazia]";
    } else {
        for (int i = topo; i >= 0; i--) {
            cout << pilha[i] << " ";
        }
    }
    cout << endl;
}

// Função push (inserção no topo)
void push(int* pilha, int& topo, int capacidade, int valor) {
    if (topo == capacidade - 1) {
        cout << "Erro: pilha cheia!" << endl;
        return;
    }
    pilha[++topo] = valor;
    cout << "Elemento inserido com sucesso." << endl;
}

// Função pop (remoção do topo)
void pop(int* pilha, int& topo) {
    if (topo == -1) {
        cout << "Erro: pilha vazia!" << endl;
        return;
    }
    cout << "Elemento removido: " << pilha[topo--] << endl;
}

int main() {
    int n;
    cout << "Informe o tamanho maximo da pilha: ";
    cin >> n;

    // Alocação dinâmica do vetor que representa a pilha
    int* pilha = new int[n];
    int topo = -1;

    int opcao, valor;
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Inserir (push)" << endl;
        cout << "2. Remover (pop)" << endl;
        cout << "3. Mostrar pilha" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Informe o valor a inserir: ";
                cin >> valor;
                push(pilha, topo, n, valor);
                mostrarPilha(pilha, topo);
                break;

            case 2:
                pop(pilha, topo);
                mostrarPilha(pilha, topo);
                break;

            case 3:
                mostrarPilha(pilha, topo);
                break;

            case 0:
                cout << "Encerrando o programa..." << endl;
                break;

            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);

    // Libera a memória alocada
    delete[] pilha;
    return 0;
}