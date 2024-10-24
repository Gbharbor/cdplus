#include <iostream>

int main() {
    int x = 10, y = 3;
    int result;

    // Adição +
    result = x + y;
    std::cout << "Adição: " << x << " + " << y << " = " << result << std::endl;

    // Subtração -
    result = x - y;
    std::cout << "Subtração: " << x << " - " << y << " = " << result << std::endl;

    // Multiplicação *
    result = x * y;
    std::cout << "Multiplicação: " << x << " * " << y << " = " << result << std::endl;

    // Divisão /
    result = x / y;
    std::cout << "Divisão: " << x << " / " << y << " = " << result << std::endl;

    // Resto da divisão inteira %
    result = x % y;
    std::cout << "Resto da divisão inteira: " << x << " % " << y << " = " << result << std::endl;

    // Incremento unário ++
    std::cout << "Valor de x antes do incremento: " << x << std::endl;
    x++;
    std::cout << "Valor de x após o incremento: " << x << std::endl;

    // Decremento unário --
    std::cout << "Valor de y antes do decremento: " << y << std::endl;
    y--;
    std::cout << "Valor de y após o decremento: " << y << std::endl;

    return 0;
};
