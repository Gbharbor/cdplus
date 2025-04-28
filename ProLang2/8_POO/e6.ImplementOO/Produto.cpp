// Produto.cpp
#include "Produto.h"

void Produto::setPreco(double p) {
    if (p > 0)
        preco = p;
}

double Produto::getPreco() {
    return preco;
}
