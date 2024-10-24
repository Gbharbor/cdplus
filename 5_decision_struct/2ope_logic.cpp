#include <iostream>

int main() {
    int x = 10, y = 20;
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

    return 0;
}