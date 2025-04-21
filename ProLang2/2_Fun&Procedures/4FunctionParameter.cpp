#include <iostream>
using namespace std;

// Função que recebe um parâmetro por valor
void dobrarValor(int numero) {
    numero = numero * 2; // modifica apenas a cópia local do parâmetro
    cout << "Dentro da função (por valor): " << numero << endl;
}

int main() {
    int valor = 10;

    cout << "Antes da função (por valor): " << valor << endl;
    dobrarValor(valor); // valor original não é alterado
    cout << "Depois da função (por valor): " << valor << endl;

    return 0;
}
#include <iostream>
using namespace std;

// Função que recebe um parâmetro por referência usando ponteiro
void dobrarValorPorReferencia(int* numero) {
    *numero = (*numero) * 2; // modifica diretamente o valor no endereço recebido
    cout << "Dentro da função (por referência): " << *numero << endl;
}

int main() {
    int valor = 10;

    cout << "\nAntes da função (por referência): " << valor << endl;
    dobrarValorPorReferencia(&valor); // envia o endereço da variável
    cout << "Depois da função (por referência): " << valor << endl;

    return 0;
}
