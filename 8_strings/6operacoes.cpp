#include <iostream> // Necessário para operações de entrada e saída
#include <string>   // Necessário para usar a classe std::string

using namespace std;

int main() {
    string str1 = "Olá";           // Inicializa a primeira string
    string str2 = " Mundo!";       // Inicializa a segunda string
    string str3;                   // String para armazenar o resultado da concatenação

    // 1. Concatenar strings
    str3 = str1 + str2;            // Concatena str1 e str2
    cout << "Concatenado: " << str3 << endl; // Saída: Olá Mundo!

    // 2. Copiar strings
    string str4 = str1;            // Cópia direta usando atribuição
    cout << "Cópia: " << str4 << endl; // Saída: Olá

    // 3. Comparar strings
    int resultadoComparacao = str1.compare("Olá"); // Compara str1 com "Olá"
    cout << "Resultado da comparação (str1 e 'Olá'): " << resultadoComparacao << endl; // Saída: 0 (iguais)

    // 4. Calcular o comprimento da string
    size_t comprimento = str1.length(); // Calcula o comprimento de str1
    cout << "Comprimento de str1: " << comprimento << endl; // Saída: 3

    // 5. Encontrar o primeiro caractere 'o' em str3
    size_t pos = str3.find('o');       // Encontra a posição do primeiro 'o' em str3
    if (pos != string::npos) {
        cout << "Primeira ocorrência de 'o': " << str3.substr(pos) << endl; // Saída: o Mundo!
    } else {
        cout << "'o' não encontrado." << endl;
    }

    return 0; // Indica que o programa terminou corretamente
}