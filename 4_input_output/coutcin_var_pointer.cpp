//COUT CIN, VAR, POINTER.
#include <iostream>  // Biblioteca para entrada e saída padrão
#include <string>    // Biblioteca para manipulação de strings
#include <iomanip>   // Biblioteca para manipulação de formato
#include <limits>    // Biblioteca para verificar os limites dos tipos de dados

using namespace std;

// Exemplo de função com constantes e ponteiros void
void exemploConstSignedChar() {
    const signed char sc = -120;  // signed char constante com valor fixo
    cout << "Valor de const signed char: " << static_cast<int>(sc) << endl;
}

void exemploConstUnsignedChar() {
    const unsigned char uc = 200; // unsigned char constante, somente valores positivos
    cout << "Valor de const unsigned char: " << static_cast<int>(uc) << endl;
}

void exemploConstChar() {
    const char letra = 'A'; // Constante de caractere
    cout << "Valor de const char: " << letra << endl;
}

void mostrarMensagem() {
    cout << "Essa função não retorna nada." << endl;
}

void exemploVoidPointer() {
    int num = 42;
    void* ptr = &num;  // Ponteiro genérico void*
    cout << "Valor de num via void*: " << *(static_cast<int*>(ptr)) << endl;
}

int main() {
    // 1. Exemplo Básico de Saída
    cout << "Hello, World!" << endl;

    // 2. Entrada e Saída com variáveis
    int idade;
    cout << "Digite sua idade: ";
    cin >> idade;
    cout << "Você tem " << idade << " anos." << endl;

    // 3. Entrada e Saída com múltiplos valores
    string nome;
    cout << "Digite o seu nome: ";
    cin >> nome;
    cout << "Olá, " << nome << ". Você tem " << idade << " anos." << endl;

    // 4. Usando std::getline para ler strings com espaços
    cin.ignore();  // Ignora o newline deixado pelo último cin
    string nome_completo;
    cout << "Digite seu nome completo: ";
    getline(cin, nome_completo);
    cout << "Olá, " << nome_completo << "!" << endl;

    // 5. Leitura de uma matriz de caracteres
    char matriz[60];
    cout << "Digite até 49 caracteres: ";
    cin.getline(matriz, 50);
    cout << "Você digitou: " << matriz << endl;

    // 6. Manipulação de variáveis com cin e cout
    double altura = 1.75;
    cout << "Nome: " << nome << ", Idade: " << idade << ", Altura: " << altura << " metros." << endl;

    // 7. Base numérica (hexadecimal)
    int numero = 10;
    cout << "Número em hexadecimal: " << hex << numero << endl;

    // 8. Formatação de números reais
    double pi = 3.14159;
    cout << fixed << "Número em ponto fixo: " << pi << endl;
    cout << "Número em notação científica: " << scientific << pi << endl;

    // 9. Espaçamento e preenchimento
    cout << "Número com largura mínima de 5: ";
    cout.width(5);
    cout << 10 << endl;  // Exibe '   10'
    cout.fill('0');
    cout.width(8);
    cout << 10 << endl;  // Exibe '00000010'

    // 10. Precisão de variáveis reais
    cout.precision(3);
    cout << fixed << "Número com precisão de 3 casas: " << pi << endl;

    // 11. Alinhamento de texto
    cout << right << "Alinhado à direita: " << 42 << endl;
    cout << left << "Alinhado à esquerda: " << 42 << endl;

    // 12. Tipos de dados e tamanhos
    cout << "char (letra): " << 'A' << " (tamanho: " << sizeof(char) << " byte)" << endl;
    cout << "signed char: " << static_cast<int>(-120) << " (tamanho: " << sizeof(signed char) << " byte)" << endl;
    cout << "unsigned char: " << static_cast<int>(240) << " (tamanho: " << sizeof(unsigned char) << " byte)" << endl;
    cout << "short: " << 32767 << " (tamanho: " << sizeof(short) << " bytes)" << endl;
    cout << "unsigned short: " << 65535 << " (tamanho: " << sizeof(unsigned short) << " bytes)" << endl;
    cout << "int: " << 2147483647 << " (tamanho: " << sizeof(int) << " bytes)" << endl;
    cout << "unsigned int: " << 4294967295 << " (tamanho: " << sizeof(unsigned int) << " bytes)" << endl;
    cout << "long: " << 2147483647L << " (tamanho: " << sizeof(long) << " bytes)" << endl;
    cout << "unsigned long: " << 4294967295UL << " (tamanho: " << sizeof(unsigned long) << " bytes)" << endl;
    cout << "long long: " << 9223372036854775807LL << " (tamanho: " << sizeof(long long) << " bytes)" << endl;
    cout << "unsigned long long: " << 18446744073709551615ULL << " (tamanho: " << sizeof(unsigned long long) << " bytes)" << endl;
    cout << "float: " << 3.14159f << " (tamanho: " << sizeof(float) << " bytes)" << endl;
    cout << "double: " << 3.141592653589793 << " (tamanho: " << sizeof(double) << " bytes)" << endl;
    cout << "long double: " << 3.14159265358979323846L << " (tamanho: " << sizeof(long double) << " bytes)" << endl;

    // Chamando funções de demonstração
    exemploConstSignedChar();
    exemploConstUnsignedChar();
    exemploConstChar();
    mostrarMensagem();
    exemploVoidPointer();

    return 0;
}