#include <string>   // Para usar o tipo string
#include <iostream> // Para entrada/saída padrão

/*
CONSTANTES EM C++
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
int age = 25;          // Literal inteiro
double rate = 4.5;    // Literal de ponto flutuante
char letter = 'B';     // Literal de caractere
// string name = "joao"; // Literal de string (comentado)
// Observação: Para usar 'string', é necessário incluir a biblioteca <string>.