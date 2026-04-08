#include <iostream>
#include <iomanip>
using namespace std;

/*
==================================================
1. Introdução - Exemplo de Classe Simples
==================================================
*/
class Pessoa {
public:
    string nome;
    int idade;

    void apresentar() {
        cout << "\n[Introducao]" << endl;
        cout << "Nome: " << nome << ", Idade: " << idade << endl;
    }
};

/*
==================================================
2. Bibliotecas Padrão - iostream e iomanip
==================================================
*/
void exemploBibliotecas() {
    double valor = 123.456789;

    cout << "\n[Bibliotecas Padrao]" << endl;
    cout << "Valor original: " << valor << endl;
    cout << "Valor formatado com 2 casas decimais: "
         << fixed << setprecision(2) << valor << endl;
}

/*
==================================================
3. Funções Inline
==================================================
*/
inline int volumeCubo(const int lado) {
    return lado * lado * lado;
}

/*
==================================================
3.1 Operador de Resolução de Escopo ::
==================================================
*/
int numero = 10; // Variável global

void exemploOperadorResolucaoEscopo() {
    int numero = 5; // Variável local

    cout << "\n[Operador de Resolucao de Escopo ::]" << endl;
    cout << "Variavel local: " << numero << endl;
    cout << "Variavel global: " << ::numero << endl;
}

/*
==================================================
4. Argumentos Default
==================================================
*/
int volumeCaixa(int comprimento = 1, int largura = 1, int altura = 1) {
    return comprimento * largura * altura;
}

/*
==================================================
5. Sobrecarga de Funções
==================================================
*/
int quadrado(int x) {
    return x * x;
}

float quadrado(float x) {
    return x * x;
}

/*
==================================================
6. Simulação de Criação de Biblioteca
==================================================
*/
int soma(int a, int b) {
    return a + b;
}

int subtrai(int a, int b) {
    return a - b;
}

/*
==================================================
Função Principal
==================================================
*/
int main() {

    // --------------------------------------------------------
    // 1. Introdução - Classe simples
    // --------------------------------------------------------
    Pessoa p;
    p.nome = "Carlos";
    p.idade = 30;
    p.apresentar();

    // --------------------------------------------------------
    // 2. Bibliotecas padrão
    // --------------------------------------------------------
    exemploBibliotecas();

    // --------------------------------------------------------
    // 3. Funções inline
    // --------------------------------------------------------
    cout << "\n[Funcoes Inline]" << endl;
    int lado = 3;
    cout << "Volume do cubo de lado " << lado << ": "
         << volumeCubo(lado) << endl;

    // --------------------------------------------------------
    // 3.1 Operador de resolução de escopo
    // --------------------------------------------------------
    exemploOperadorResolucaoEscopo();

    // --------------------------------------------------------
    // 4. Argumentos default
    // --------------------------------------------------------
    cout << "\n[Argumentos Default]" << endl;
    cout << "Volume padrao: " << volumeCaixa() << endl;
    cout << "Volume (2 x 3 x 4): " << volumeCaixa(2, 3, 4) << endl;
    cout << "Volume (5 x 2 x 1): " << volumeCaixa(5, 2) << endl;

    // --------------------------------------------------------
    // 5. Sobrecarga de funções
    // --------------------------------------------------------
    cout << "\n[Sobrecarga de Funcoes]" << endl;
    cout << "Quadrado de 4 (int): " << quadrado(4) << endl;
    cout << "Quadrado de 5.5 (float): " << quadrado(5.5f) << endl;

    // --------------------------------------------------------
    // 6. Simulação de biblioteca
    // --------------------------------------------------------
    cout << "\n[Simulacao de Biblioteca]" << endl;
    cout << "Soma: " << soma(10, 5) << endl;
    cout << "Subtracao: " << subtrai(10, 5) << endl;

    return 0;
}