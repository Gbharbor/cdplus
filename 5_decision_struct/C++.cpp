#include <iostream>

int main() {
    // Seção de Operadores Aritméticos
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

    // Seção de Operadores Lógicos
    bool resultado;

    // Operador Lógico AND (&&)
    resultado = (x > 5) && (y < 30);
    std::cout << "Resultado de (x > 5) && (y < 30): " << resultado << std::endl; // Esperado: 1 (verdadeiro)

    // Operador Lógico OR (||)
    resultado = (x < 5) || (y > 15);
    std::cout << "Resultado de (x < 5) || (y > 15): " << resultado << std::endl; // Esperado: 1 (verdadeiro)

    // Operador Lógico NOT (!)
    resultado = !(x == 10);
    std::cout << "Resultado de !(x == 10): " << resultado << std::endl; // Esperado: 0 (falso)

    // Seção de Operadores Relacionais
    std::cout << "\nOperadores Relacionais:\n";
    std::cout << "x == y: " << (x == y) << std::endl;  // Falso (0)
    std::cout << "x != y: " << (x != y) << std::endl;  // Verdadeiro (1)
    std::cout << "x > y: " << (x > y) << std::endl;    // Falso (0)
    std::cout << "x < y: " << (x < y) << std::endl;    // Verdadeiro (1)
    std::cout << "x >= y: " << (x >= y) << std::endl;  // Falso (0)
    std::cout << "x <= y: " << (x <= y) << std::endl;  // Verdadeiro (1)

    // Seção de Expressões Simples e Compostas
    std::cout << "\nExpressões:\n";
    // Expressão simples
    if (x < y) {
        std::cout << "x é menor que y" << std::endl;  // Apenas uma condição é avaliada
    }

    // Expressão composta
    if ((x > 5) && (y < 30)) {
        std::cout << "x é maior que 5 E y é menor que 30" << std::endl;  // Ambas as condições precisam ser verdadeiras
    }

    return 0;
}