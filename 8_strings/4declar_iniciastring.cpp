#include <iostream> // Necessário para operações de entrada e saída
#include <string>   // Necessário para usar a classe std::string

int main() {
    // Declarando e inicializando uma string em C++
    std::string str1 = "Olá, mundo!";  // Usa a classe std::string para declarar e inicializar
    std::string str2("Olá, C++!");      // Outra forma de inicialização usando o construtor

    // Imprimindo as strings
    std::cout << "String 1: " << str1 << std::endl;  // Imprime a primeira string
    std::cout << "String 2: " << str2 << std::endl;  // Imprime a segunda string

    return 0; // Indica que o programa terminou corretamente
}
