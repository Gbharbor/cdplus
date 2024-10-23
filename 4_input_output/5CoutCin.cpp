#include <iostream>
#include <string>
#include <iomanip> // Necessário para manipulação de formato

int main() {
    // 1. Exemplo Básico de Saída
    std::cout << "Hello, World!" << std::endl;

    // 2. Exemplo de Entrada e Saída
    int idade;
    std::cout << "Digite sua idade: ";
    std::cin >> idade;
    std::cout << "Você tem " << idade << " anos." << std::endl;

    // 3. Exemplo com Múltiplos Valores
    std::string nome;
    std::cout << "Digite o seu nome: ";
    std::cin >> nome;
    std::cout << "Olá, " << nome << ". Você tem " << idade << " anos." << std::endl;

    // 4. Usando std::getline para Ler Nomes com Espaços
    std::cin.ignore(); // Ignora o newline deixado pelo último std::cin
    std::string nome_completo;
    std::cout << "Digite seu nome completo: ";
    std::getline(std::cin, nome_completo);
    std::cout << "Olá, " << nome_completo << "!" << std::endl;

    // 5. Leitura de uma Matriz de Caracteres
    char matriz[60];
    std::cout << "Digite até 49 caracteres: ";
    std::cin.getline(matriz, 50);
    std::cout << "Você digitou: " << matriz << std::endl;

    // 6. Manipulando Tipos de Dados com cin e cout
    double altura = 1.75;
    std::cout << "Nome: " << nome << ", Idade: " << idade << ", Altura: " << altura << " metros." << std::endl;

    // 7. Escolher Base Numérica
    int numero = 10;
    std::cout << "Número em hexadecimal: " << std::hex << numero << std::endl;

    // 8. Formatação de Números Reais
    double pi = 3.14159;
    std::cout << std::fixed << "Número em ponto fixo: " << pi << std::endl;
    std::cout << "Número em notação científica: " << std::scientific << pi << std::endl;

    // 9. Espaçamento de Texto e Preenchimento
    std::cout << "Número com largura mínima de 5: ";
    std::cout.width(5);
    std::cout << 10 << std::endl; // Exibe '   10'
    std::cout.fill('0');
    std::cout.width(8);
    std::cout << 10 << std::endl; // Exibe '00000010'

    // 10. Precisão de Variáveis Reais
    std::cout.precision(3);
    std::cout << std::fixed << "Número com precisão de 3 casas: " << pi << std::endl;

    // 11. Alinhamento de Texto
    std::cout << std::right << "Alinhado à direita: " << 42 << std::endl;
    std::cout << std::left << "Alinhado à esquerda: " << 42 << std::endl;

    return 0;
};