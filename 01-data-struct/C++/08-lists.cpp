#include <iostream>
using namespace std;

// ------------------------------------------------------
// LISTA ESTÁTICA SIMPLES
// ------------------------------------------------------
const int TAM_MAX = 100;
int lista[TAM_MAX];      // vetor que armazena os elementos
int preenchidos = 0;     // quantidade atual de elementos


// ------------------------------------------------------
// MOSTRAR LISTA
// ------------------------------------------------------
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


// ------------------------------------------------------
// BUSCAR ELEMENTO (BUSCA SEQUENCIAL)
// Retorna o índice ou -1 se não encontrar.
// ------------------------------------------------------
int buscarElemento(int chave) {

    for (int i = 0; i < preenchidos; i++) {
        if (lista[i] == chave)
            return i;
    }

    return -1;
}


// ------------------------------------------------------
// INSERIR ELEMENTO NA LISTA
// ------------------------------------------------------
void inserirElemento() {

    int valor;

    cout << "Digite o valor a ser inserido: ";
    cin >> valor;

    if (preenchidos >= TAM_MAX) {
        cout << "Erro: Lista cheia!\n";
        return;
    }

    // evita duplicatas
    if (buscarElemento(valor) != -1) {
        cout << "Erro: Elemento ja existe!\n";
        return;
    }

    lista[preenchidos++] = valor;

    cout << "Elemento inserido com sucesso.\n";
}


// ------------------------------------------------------
// REMOVER ELEMENTO DA LISTA
// ------------------------------------------------------
void removerElemento() {

    int chave;

    cout << "Digite o valor a ser removido: ";
    cin >> chave;

    int pos = buscarElemento(chave);

    if (pos == -1) {
        cout << "Erro: Elemento nao encontrado.\n";
        return;
    }

    // desloca os elementos para preencher o espaço
    for (int i = pos; i < preenchidos - 1; i++) {
        lista[i] = lista[i + 1];
    }

    preenchidos--;

    cout << "Elemento removido com sucesso.\n";
}


// ------------------------------------------------------
// MOSTRAR MENOR E MAIOR VALOR DA LISTA
// ------------------------------------------------------
void menorMaior() {

    if (preenchidos == 0) {
        cout << "Lista vazia.\n";
        return;
    }

    int menor = lista[0];
    int maior = lista[0];

    for (int i = 1; i < preenchidos; i++) {

        if (lista[i] < menor)
            menor = lista[i];

        if (lista[i] > maior)
            maior = lista[i];
    }

    cout << "Menor valor: " << menor << endl;
    cout << "Maior valor: " << maior << endl;
}


// ------------------------------------------------------
// MENU
// ------------------------------------------------------
void menu() {

    cout << "\n======= MENU - OPERACOES EM LISTA =======\n";
    cout << "1. Inserir elemento\n";
    cout << "2. Remover elemento\n";
    cout << "3. Buscar elemento\n";
    cout << "4. Mostrar menor e maior\n";
    cout << "5. Mostrar lista\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
}


// ------------------------------------------------------
// MAIN
// ------------------------------------------------------
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
                    cout << "Elemento encontrado na posicao " << pos << endl;
                else
                    cout << "Elemento nao encontrado.\n";

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
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}