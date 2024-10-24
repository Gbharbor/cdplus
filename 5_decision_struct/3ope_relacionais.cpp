//Operadores relacionais
#include <iostream>

int main() {
    int x = 10, y = 20;

    // Igual a (==)
    std::cout << "x == y: " << (x == y) << std::endl;  // Falso (0)

    // Diferente de (!=)
    std::cout << "x != y: " << (x != y) << std::endl;  // Verdadeiro (1)

    // Maior que (>)
    std::cout << "x > y: " << (x > y) << std::endl;    // Falso (0)

    // Menor que (<)
    std::cout << "x < y: " << (x < y) << std::endl;    // Verdadeiro (1)

    // Maior ou igual a (>=)
    std::cout << "x >= y: " << (x >= y) << std::endl;  // Falso (0)

    // Menor ou igual a (<=)
    std::cout << "x <= y: " << (x <= y) << std::endl;  // Verdadeiro (1)

    return 0;
}