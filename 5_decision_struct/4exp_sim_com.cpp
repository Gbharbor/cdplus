//Expressoes Simples e Composta
//Simples : avalia uma unica condicoes ou operacao
//Composta: Combina varias condicoes, utilizando operadores logicos como && || ou !
#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // Expressão simples
    if (x < y) {
        std::cout << "x é menor que y" << std::endl;
    }

    // Expressão composta
    if ((x > 5) && (y < 30)) {
        std::cout << "x é maior que 5 E y é menor que 30" << std::endl;
    }

    return 0;
}