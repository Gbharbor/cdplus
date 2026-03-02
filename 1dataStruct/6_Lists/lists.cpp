#include <iostream>
using namespace std;

const int TAM_MAX = 100;
int lista[TAM_MAX];
int preenchidos = 0;

void mostrarLista() {
    if (preenchidos == 0) {
        cout << "Lista vazia.\n";
        return;
    }

    cout << "Lista atual: ";
    for (int i = 0; i < preenchidos; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
}

int buscarElemento(int chave) {
    for (int i = 0; i < preenchidos; i++) {
        if (lista[i] == chave)
            return i;
    }
    return -1;
}

void inserirElemento() {
    int valor;
    cout << "Digite o valor a ser inserido: ";
    cin >> valor;

    if (preenchidos >= TAM_MAX) {
        cout << "Erro: Lista cheia!\n";
        return;
    }

    if (buscarElemento(valor) != -1) {
        cout << "Erro: Elemento já existe!\n";
        return;
    }

    lista[preenchidos++] = valor;
    cout << "Elemento inserido com sucesso.\n";
}

void removerElemento() {
    int chave;
    cout << "Digite o valor a ser removido: ";
    cin >> chave;

    int pos = buscarElemento(chave);
    if (pos == -1) {
        cout << "Erro: Elemento não encontrado.\n";
        return;
    }

    for (int i = pos; i < preenchidos - 1; i++) {
        lista[i] = lista[i + 1];
    }
    preenchidos--;
    cout << "Elemento removido com sucesso.\n";
}

void menorMaior() {
    if (preenchidos == 0) {
        cout << "Lista vazia.\n";
        return;
    }

    int menor = lista[0], maior = lista[0];
    for (int i = 1; i < preenchidos; i++) {
        if (lista[i] < menor) menor = lista[i];
        if (lista[i] > maior) maior = lista[i];
    }

    cout << "Menor valor: " << menor << "\nMaior valor: " << maior << endl;
}

void menu() {
    cout << "\n======= MENU - OPERACOES EM LISTA =======\n";
    cout << "1. Inserir elemento\n";
    cout << "2. Remover elemento\n";
    cout << "3. Buscar elemento\n";
    cout << "4. Mostrar menor e maior\n";
    cout << "5. Mostrar lista\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opção: ";
}

int main() {
    int opcao;

    do {
        menu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                inserirElemento();
                break;
            case 2:
                removerElemento();
                break;
            case 3: {
                int chave;
                cout << "Digite o valor a ser buscado: ";
                cin >> chave;
                int pos = buscarElemento(chave);
                if (pos != -1)
                    cout << "Elemento encontrado na posição " << pos << endl;
                else
                    cout << "Elemento não encontrado.\n";
                break;
            }
            case 4:
                menorMaior();
                break;
            case 5:
                mostrarLista();
                break;
            case 0:
                cout << "Encerrando programa...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}
