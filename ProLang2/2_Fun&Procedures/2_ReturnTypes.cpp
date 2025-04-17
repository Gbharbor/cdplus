// 2 - Tipos de Retornos
#include <iostream>
#include <string>
using namespace std;

// Função que retorna um valor inteiro (int)
int soma(int a, int b) {
    return a + b;
}

// Função que retorna um valor de ponto flutuante (float)
float media(float a, float b) {
    return (a + b) / 2;
}

// Função que retorna um valor booleano (bool)
bool ehPar(int num) {
    return num % 2 == 0;
}

// Função que retorna um caractere (char)
char primeiroCaractere(string str) {
    return str[0];
}

// Função que não retorna valor (void)
void imprimirMensagem() {
    cout << "Esta é uma mensagem!" << endl;
}

// Função que retorna um ponteiro (int*)
int* encontrarMaximo(int arr[], int tamanho) {
    int* max = &arr[0];
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] > *max) {
            max = &arr[i];
        }
    }
    return max;
}

// Função que retorna uma referência (int&)
int& maiorNumero(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Estrutura para representar um ponto (struct)
struct Ponto {
    int x, y;
};

// Função que retorna uma estrutura (struct)
Ponto criarPonto(int x, int y) {
    Ponto p = {x, y};
    return p;
}

// Função que retorna um objeto de classe (classe)
class Pessoa {
public:
    string nome;
    int idade;

    Pessoa(string nome, int idade) : nome(nome), idade(idade) {}
};

// Função que retorna um objeto de classe
Pessoa criarPessoa(string nome, int idade) {
    return Pessoa(nome, idade);
}

// Função que retorna uma string (std::string)
std::string saudacao() {
    return "Olá, bem-vindo ao C++!";
}

int main() {
    // Demonstração das funções com diferentes tipos de retorno

    // Função com retorno inteiro
    int resultadoSoma = soma(10, 5);
    cout << "Soma: " << resultadoSoma << endl;

    // Função com retorno float
    float resultadoMedia = media(5.0, 7.0);
    cout << "Média: " << resultadoMedia << endl;

    // Função com retorno booleano
    bool resultadoPar = ehPar(6);
    cout << "6 é par? " << (resultadoPar ? "Sim" : "Não") << endl;

    // Função com retorno char
    char caractere = primeiroCaractere("Hello");
    cout << "Primeiro caractere: " << caractere << endl;

    // Função com retorno void (não retorna nada)
    imprimirMensagem();

    // Função com retorno ponteiro (int*)
    int arr[] = {1, 2, 3, 4, 5};
    int* maximo = encontrarMaximo(arr, 5);
    cout << "Maior número: " << *maximo << endl;

    // Função com retorno referência (int&)
    int a = 10, b = 20;
    int& maior = maiorNumero(a, b);
    cout << "Maior número: " << maior << endl;

    // Função com retorno struct
    Ponto p = criarPonto(3, 4);
    cout << "Ponto: (" << p.x << ", " << p.y << ")" << endl;

    // Função com retorno objeto da classe
    Pessoa pessoa = criarPessoa("Carlos", 25);
    cout << "Pessoa: " << pessoa.nome << ", Idade: " << pessoa.idade << endl;

    // Função com retorno string
    std::string saudacaoMsg = saudacao();
    cout << saudacaoMsg << endl;

    return 0;
}