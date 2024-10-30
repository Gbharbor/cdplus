#include <iostream>
#include <string>

int main() {
    // 1. Declaração e Inicialização
    std::string str1 = "Hello"; // Inicializa uma string
    std::string str2 = "World"; // Outra string

    // 2. Concatenação de Strings
    std::string str3 = str1 + ", " + str2 + "!"; // Concatena strings
    std::cout << "Concatenação: " << str3 << std::endl; // Saída: Hello, World!

    // 3. Comprimento da String
    std::cout << "Comprimento de str3: " << str3.length() << std::endl; // Saída: 13

    // 4. Acesso a Caracteres
    std::cout << "Primeiro caractere de str3: " << str3[0] << std::endl; // Saída: H

    // 5. Substrings
    std::string substr = str3.substr(0, 5); // Extrai os primeiros 5 caracteres
    std::cout << "Substring: " << substr << std::endl; // Saída: Hello

    // 6. Modificação de String
    str3[0] = 'h'; // Modifica o primeiro caractere
    std::cout << "Após modificação: " << str3 << std::endl; // Saída: hello, World!

    // 7. Busca
    size_t pos = str3.find("World"); // Busca "World"
    if (pos != std::string::npos) {
        std::cout << "'World' encontrado na posição: " << pos << std::endl; // Saída: 7
    }

    // 8. Substituição
    str3.replace(pos, 5, "C++"); // Substitui "World" por "C++"
    std::cout << "Após substituição: " << str3 << std::endl; // Saída: hello, C++!

    // 9. Limpeza
    str3.erase(5, 2); // Remove a vírgula e o espaço
    std::cout << "Após limpeza: " << str3 << std::endl; // Saída: hello C++!

    // 10. Conversão de String para Número
    std::string numStr = "12345";
    int num = std::stoi(numStr); // Converte string para inteiro
    std::cout << "Número convertido: " << num << std::endl; // Saída: 12345

    // 11. Conversão de Número para String
    int age = 30;
    std::string ageStr = std::to_string(age); // Converte inteiro para string
    std::cout << "Idade como string: " << ageStr << std::endl; // Saída: 30

    return 0; // Indica que o programa terminou corretamente
}