#include <iostream>
#include <iomanip>
using namespace std;

/*
========================================
1. Introdução – Exemplo de Classe Simples
========================================
*/
class Pessoa {
public:
    string nome;
    int idade;

    void apresentar() {
        cout << "\n[Introducao]\n";
        cout << "Nome: " << nome << ", Idade: " << idade << endl;
    }
};

/*
========================================
2. Bibliotecas Padrão – iostream e iomanip
========================================
*/
void exemploBibliotecas() {
    double valor = 123.456789;

    cout << "\n[Bibliotecas Padrao]\n";
    cout << "Valor normal: " << valor << endl;
    cout << "Valor formatado: " << fixed << setprecision(2) << valor << endl;
}

/*
========================================
3. Funções Inline
========================================
*/
inline int volumeCubo(const int lado) {
    return lado * lado * lado;
}

/*
========================================
3.1 Operador Unário de Resolução de Escopo ::
========================================
*/
int numero = 10; // Variável global

void exemploOperadorUnario() {
    int numero = 5; // Variável local

    cout << "\n[Operador Unario de Resolucao de Escopo]\n";
    cout << "Variável local: " << numero << endl;
    cout << "Variável global: " << ::numero << endl;
}

/*
========================================
4. Argumentos Default
========================================
*/
int volumeCaixa(int comprimento = 1, int largura = 1, int altura = 1) {
    return comprimento * largura * altura;
}

/*
========================================
5. Sobrecarga de Funções
========================================
*/
int quadrado(int x) {
    return x * x;
}

float quadrado(float x) {
    return x * x;
}

/*
========================================
6. Criação de Biblioteca (simulado aqui)
========================================
*/
int soma(int a, int b) {
    return a + b;
}

int subtrai(int a, int b) {
    return a - b;
}

/*
========================================
Função Principal
========================================
*/
int main() {
    // 1. Introdução
    Pessoa p;
    p.nome = "Carlos";
    p.idade = 30;
    p.apresentar();

    // 2. Bibliotecas Padrão
    exemploBibliotecas();

    // 3. Função Inline
    cout << "\n[Funcoes Inline]\n";
    int lado = 3;
    cout << "Volume do cubo: " << volumeCubo(lado) << endl;

    // 3.1 Operador Unário
    exemploOperadorUnario();

    // 4. Argumentos Default
    cout << "\n[Argumentos Default]\n";
    cout << "Volume padrão: " << volumeCaixa() << endl;
    cout << "Volume (2x3x4): " << volumeCaixa(2, 3, 4) << endl;
    cout << "Volume (5x2): " << volumeCaixa(5, 2) << endl;

    // 5. Sobrecarga de Funções
    cout << "\n[Sobrecarga de Funcoes]\n";
    cout << "Quadrado de 4 (int): " << quadrado(4) << endl;
    cout << "Quadrado de 5.5 (float): " << quadrado(5.5f) << endl;

    // 6. "Criação de Biblioteca" (simulado)
    cout << "\n[Simulacao de Biblioteca]\n";
    cout << "Soma: " << soma(10, 5) << endl;
    cout << "Subtração: " << subtrai(10, 5) << endl;

    return 0;
}
