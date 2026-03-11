#include <iostream>
using namespace std;

int main() {
    // ==========================================================
    // AULA 2 - OPERADORES E ESTRUTURAS CONDICIONAIS EM C++
    // ==========================================================

    // ==========================================================
    // 1. OPERADORES ARITMETICOS
    // ==========================================================
    int x = 10, y = 3;
    int result;

    cout << "=== OPERADORES ARITMETICOS ===" << endl;

    // Adicao
    result = x + y;
    cout << "Adicao: " << x << " + " << y << " = " << result << endl;

    // Subtracao
    cout << "Subtracao: " << x << " - " << y << " = " << x - y << endl;

    // Multiplicacao
    cout << "Multiplicacao: " << x << " * " << y << " = " << x * y << endl;

    // Divisao inteira
    cout << "Divisao inteira: " << x << " / " << y << " = " << x / y << endl;

    // Resto da divisao inteira
    result = x % y;
    cout << "Resto da divisao inteira: " << x << " % " << y << " = " << result << endl;

    // Incremento
    cout << "\nValor de x antes do incremento: " << x << endl;
    x++;
    cout << "Valor de x apos o incremento: " << x << endl;

    // Decremento
    cout << "Valor de y antes do decremento: " << y << endl;
    y--;
    cout << "Valor de y apos o decremento: " << y << endl;

    // ==========================================================
    // 2. OPERADORES LOGICOS
    // ==========================================================
    bool resultado;

    cout << "\n=== OPERADORES LOGICOS ===" << endl;

    // Operador AND (&&)
    resultado = (x > 5) && (y < 30);
    cout << "(x > 5) && (y < 30) = " << resultado << endl;

    // Operador OR (||)
    resultado = (x < 5) || (y > 15);
    cout << "(x < 5) || (y > 15) = " << resultado << endl;

    // Operador NOT (!)
    resultado = !(x == 10);
    cout << "!(x == 10) = " << resultado << endl;

    // ==========================================================
    // 3. CONDICOES SIMPLES COM IF
    // ==========================================================
    cout << "\n=== CONDICOES SIMPLES ===" << endl;

    if (x < y) {
        cout << "Expressao simples: x e menor que y." << endl;
    }

    if ((x > 5) && (y < 30)) {
        cout << "x e maior que 5 e y e menor que 30." << endl;
    }

    // ==========================================================
    // 4. ESTRUTURA CONDICIONAL IF / ELSE IF / ELSE
    // ==========================================================
    int idade;

    cout << "\n=== CLASSIFICACAO POR IDADE ===" << endl;
    cout << "Insira sua idade: ";
    cin >> idade;

    // Verificacao basica
    if (idade < 0) {
        cout << "Idade invalida!" << endl;
    } else if (idade < 18) {
        cout << "Menor de idade!" << endl;
    } else {
        cout << "Maior de idade!" << endl;
    }

    // Classificacao mais detalhada
    if (idade < 0) {
        cout << "Nao e possivel classificar uma idade negativa." << endl;
    } else if (idade < 10) {
        cout << "Voce e uma crianca." << endl;
    } else if (idade < 13) {
        cout << "Voce e um pre-adolescente." << endl;
    } else if (idade < 20) {
        cout << "Voce e um adolescente." << endl;
    } else if (idade < 65) {
        cout << "Voce e um adulto." << endl;
    } else {
        cout << "Voce e um idoso." << endl;
    }

    return 0;
}