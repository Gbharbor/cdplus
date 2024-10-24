//Operadores Logicos ou Relacionais ou conectivo logico.
//é usado para expressar condicoes e operacoes booleanas.
//and && retorna true se ambas as condicoes for verdade
//or || retorna true se pelo menos uma for verdade
// not ! inverte o valor logico se for vdd, torna se falso e vice versa.
#include <stdio.h>

int main() {
    int x = 10, y = 20;
    int resultado;

    // Operador Lógico AND (&&)
    resultado = (x > 5) && (y < 30);
    printf("Resultado de (x > 5) && (y < 30): %d\n", resultado); // Esperado: 1 (verdadeiro)

    // Operador Lógico OR (||)
    resultado = (x < 5) || (y > 15);
    printf("Resultado de (x < 5) || (y > 15): %d\n", resultado); // Esperado: 1 (verdadeiro)

    // Operador Lógico NOT (!)
    resultado = !(x == 10);
    printf("Resultado de !(x == 10): %d\n", resultado); // Esperado: 0 (falso)

    return 0;
}