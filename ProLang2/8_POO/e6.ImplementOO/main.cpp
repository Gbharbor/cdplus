#include <iostream>
#include "Produto.h"
using namespace std;

int main() {
    Produto livro;
    livro.setPreco(79.90);
    cout << "Preço do livro: R$ " << livro.getPreco() << endl;
    return 0;
}