// calc.cpp
#include "calc.h"
#include <iostream>

float soma(float a, float b) {
    return a + b;
}

float subtracao(float a, float b) {
    return a - b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float divisao(float a, float b) {
    if (b == 0) {
        std::cerr << "Erro: divisão por zero!\n";
        return 0;
    }
    return a / b;
}