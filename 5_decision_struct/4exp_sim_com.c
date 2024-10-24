//Expressoes Simples e Composta
//Simples : avalia uma unica condicoes ou operacao
//Composta: Combina varias condicoes, utilizando operadores logicos como && || ou !
#include <stdio.h>

int main() {
    int x = 10;
    int y = 20;

    // Expressão simples
    if (x < y) {
        printf("x é menor que y\n");  // Apenas uma condição é avaliada
    }

    // Expressão composta
    if ((x > 5) && (y < 30)) {
        printf("x é maior que 5 E y é menor que 30\n");  // Ambas as condições precisam ser verdadeiras
    }

    return 0;
}