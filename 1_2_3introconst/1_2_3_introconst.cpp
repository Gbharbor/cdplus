#include <iostream> // Para entrada e saída padrão
#include <string>   // Para usar o tipo string
#include <cstdio> // Para usar a biblioteca C

// Dessa forma, consigo usar a linguagem C dentro do C++ puxando suas bibliotecas.
extern "C" {
    #include <stdio.h>   // Biblioteca padrão de entrada/saída em C
    #include <stdlib.h>  // Biblioteca padrão de utilidades em C
    #include <string.h>  // Biblioteca padrão de manipulação de strings em C
}

using namespace std; // Para simplificar o uso dos elementos da biblioteca padrão

// CONSTANTES EM C++
/*
Constantes são valores fixos que não podem ser alterados após serem definidos.

- Tipo: const
  A palavra-chave const define uma constante que respeita as regras de escopo,
  garantindo que seu valor não possa ser alterado em nenhum momento.
*/
const double PI = 3.14159;    // Constante do tipo double
const int maxAge = 100;       // Constante do tipo int

// Tipo: constexpr
// A palavra-chave constexpr é usada para valores que devem ser conhecidos e avaliados em tempo de compilação.
constexpr int square(int x) { 
    return x * x; 
}
constexpr int value = square(5); // Avaliado em tempo de compilação

// Tipo: #DEFINE
// A diretiva define é uma diretiva de pré-processador que cria macros.
// É menos segura porque não respeita escopo e não fornece verificação de tipo.
#define max_size 100
int array[max_size]; // Declaração de um array com tamanho máximo

// LITERAIS
// Literais são valores fixos que são colocados diretamente no código.
int age = 25;         // Literal inteiro
double rate = 4.5;    // Literal de ponto flutuante
char letter = 'B';    // Literal de caractere
string name = "Joao"; // Literal de string

int main() {
    // Exemplo 1: Usando cout com namespace std
    cout << "Hello world" << endl << "Hello again" << endl;

    // Exemplo 2: Usando cout sem namespace std
    std::cout << "Hello World (sem using namespace std)" << std::endl;

    // Exemplo 3: Usando printf da biblioteca C
    printf("Hello\n\t\aWorld (usando printf)\n");

    // Exibindo as constantes e literais
    cout << "Constantes e Literais:" << endl;
    cout << "PI: " << PI << endl;
    cout << "maxAge: " << maxAge << endl;
    cout << "Valor calculado em tempo de compilação (constexpr): " << value << endl;
    cout << "Tamanho máximo do array (define): " << max_size << endl;

    // Exibindo os literais
    cout << "Idade: " << age << endl;
    cout << "Taxa: " << rate << endl;
    cout << "Letra: " << letter << endl;
    cout << "Nome: " << name << endl;

    return 0; // Indica que o programa terminou com sucesso