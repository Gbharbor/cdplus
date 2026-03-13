#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// ==========================================================
// 1. CONSTANTES E DEFINIÇÕES
// ==========================================================

// Constante tradicional
const double PI = 3.141592653589793;
const int MAX_AGE = 100;

// Macro (forma antiga de definir constantes)
#define MAX_SIZE 100

// constexpr: valor calculado em tempo de compilação
constexpr int square(int x) {
    return x * x;
}

constexpr int VALUE = square(5);

// ==========================================================
// 2. VARIÁVEIS GLOBAIS
// ==========================================================

int age = 25;
float height = 1.75f;
char letter = 'B';
char initial = 'A';
string name = "Joao";
double rate = 4.5;
bool isApproved = true;

// Tipos inteiros
int numbers[5] = {1, 2, 3, 4, 5};
signed int signedNumber = -100;
unsigned int unsignedNumber = 100;
short int smallN = 3200;
int standardN = 100000;
long int largeN = 1000000000;
long long int veryLargeN = 10000000000000000LL;

// ==========================================================
// 3. STRUCT
// ==========================================================

struct Person {
    string name;
    int age;
    float height;
};

// ==========================================================
// 4. FUNÇÕES
// ==========================================================

// Função sem retorno
void displayMessage() {
    cout << "Esta funcao nao retorna nada, por isso o tipo dela e void." << endl;
}

// Exemplo com const signed char
void exConstSignedChar() {
    const signed char sc = -120;
    cout << "Valor de const signed char: " << static_cast<int>(sc) << endl;
}

// Exemplo com const unsigned char
void exConstUnsignedChar() {
    const unsigned char uc = 200;
    cout << "Valor de const unsigned char: " << static_cast<int>(uc) << endl;
}

// Exemplo com const char
void exConstChar() {
    const char letra = 'A';
    cout << "Valor de const char: " << letra << endl;
}

// Exemplo de ponteiro generico void*
void exVoidPointer() {
    int num = 42;
    void* ptr = &num;

    cout << "Valor de num via void*: " 
         << *(static_cast<int*>(ptr)) << endl;
}

// ==========================================================
// 5. FUNÇÃO PRINCIPAL
// ==========================================================

int main() {
    // ======================================================
    // 5.1 SAÍDA BÁSICA
    // ======================================================
    cout << "Hello World" << endl;
    std::cout << "Hello World (sem using namespace std)" << std::endl;

    // ======================================================
    // 5.2 CONSTANTES E LITERAIS
    // ======================================================
    cout << "\n=== CONSTANTES E LITERAIS ===" << endl;
    cout << "PI: " << PI << endl;
    cout << "MAX_AGE: " << MAX_AGE << endl;
    cout << "Valor constexpr (square(5)): " << VALUE << endl;
    cout << "MAX_SIZE (#define): " << MAX_SIZE << endl;

    // ======================================================
    // 5.3 VARIÁVEIS BÁSICAS
    // ======================================================
    cout << "\n=== VARIAVEIS BASICAS ===" << endl;
    cout << "Idade: " << age << endl;
    cout << "Altura: " << height << endl;
    cout << "Letra: " << letter << endl;
    cout << "Inicial: " << initial << endl;
    cout << "Nome: " << name << endl;
    cout << "Taxa: " << rate << endl;
    cout << "Aprovado: " << (isApproved ? "Sim" : "Nao") << endl;

    // ======================================================
    // 5.4 ARRAY
    // ======================================================
    cout << "\n=== ARRAY ===" << endl;
    cout << "Numeros no array: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    // ======================================================
    // 5.5 STRUCT
    // ======================================================
    cout << "\n=== STRUCT ===" << endl;
    Person person;
    person.name = "Joao";
    person.age = 30;
    person.height = 1.82f;

    cout << "Pessoa -> Nome: " << person.name
         << ", Idade: " << person.age
         << ", Altura: " << person.height << endl;

    // ======================================================
    // 5.6 TIPOS ASSINADOS E NAO ASSINADOS
    // ======================================================
    cout << "\n=== TIPOS ASSINADOS E NAO ASSINADOS ===" << endl;
    cout << "signed int: " << signedNumber << endl;
    cout << "unsigned int: " << unsignedNumber << endl;

    // ======================================================
    // 5.7 TAMANHOS DIFERENTES DE INTEIROS
    // ======================================================
    cout << "\n=== TIPOS INTEIROS DE TAMANHOS DIFERENTES ===" << endl;
    cout << "short: " << smallN << endl;
    cout << "int: " << standardN << endl;
    cout << "long: " << largeN << endl;
    cout << "long long: " << veryLargeN << endl;

    // ======================================================
    // 5.8 FUNÇÃO VOID
    // ======================================================
    cout << "\n=== FUNCAO VOID ===" << endl;
    displayMessage();

    // ======================================================
    // 5.9 ENTRADA DE DADOS COM CIN
    // ======================================================
    cout << "\n=== ENTRADA DE DADOS ===" << endl;

    int idade;
    cout << "Digite sua idade: ";
    cin >> idade;
    cout << "Voce tem " << idade << " anos." << endl;

    string nome;
    cout << "Digite o seu primeiro nome: ";
    cin >> nome;
    cout << "Ola, " << nome << ". Voce tem " << idade << " anos." << endl;

    // Limpa o buffer antes do getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string full_name;
    cout << "Digite seu nome completo: ";
    getline(cin, full_name);
    cout << "Ola, " << full_name << "!" << endl;

    // ======================================================
    // 5.10 STRING C (ARRAY DE CHAR)
    // ======================================================
    cout << "\n=== STRING EM ESTILO C (char[]) ===" << endl;
    char matriz[50];
    cout << "Digite ate 49 caracteres: ";
    cin.getline(matriz, 50);
    cout << "Voce digitou: " << matriz << endl;

    // ======================================================
    // 5.11 BASE NUMÉRICA
    // ======================================================
    cout << "\n=== BASE NUMERICA ===" << endl;
    int numero = 10;
    cout << "Decimal: " << dec << numero << endl;
    cout << "Hexadecimal: " << hex << numero << endl;
    cout << "Octal: " << oct << numero << endl;
    cout << dec; // volta para decimal

    // ======================================================
    // 5.12 FORMATACAO DE NUMEROS REAIS
    // ======================================================
    cout << "\n=== FORMATACAO DE NUMEROS REAIS ===" << endl;
    double pi = 3.14159;

    cout << "Ponto fixo: " << fixed << pi << endl;
    cout << "Notacao cientifica: " << scientific << pi << endl;

    // Resetando formato
    cout.unsetf(ios::floatfield);

    cout << fixed << setprecision(3);
    cout << "Numero com 3 casas decimais: " << pi << endl;

    // ======================================================
    // 5.13 ALINHAMENTO E PREENCHIMENTO
    // ======================================================
    cout << "\n=== ALINHAMENTO E PREENCHIMENTO ===" << endl;

    cout << "Numero com largura 5, alinhado a direita: ";
    cout << right << setw(5) << 10 << endl;

    cout << "Numero com largura 8, alinhado a esquerda e preenchido com 0: ";
    cout << left << setfill('0') << setw(8) << 10 << endl;

    cout << "Numero com largura 8, alinhado a esquerda e preenchido com espacos: ";
    cout << setfill(' ') << setw(8) << 10 << endl;

    // Reset simples do alinhamento
    cout << right;

    // ======================================================
    // 5.14 TAMANHO DOS TIPOS DE DADOS
    // ======================================================
    cout << "\n=== TAMANHO DOS TIPOS DE DADOS ===" << endl;
    cout << "char: " << sizeof(char) << " byte(s)" << endl;
    cout << "signed char: " << sizeof(signed char) << " byte(s)" << endl;
    cout << "unsigned char: " << sizeof(unsigned char) << " byte(s)" << endl;
    cout << "short: " << sizeof(short) << " byte(s)" << endl;
    cout << "int: " << sizeof(int) << " byte(s)" << endl;
    cout << "long: " << sizeof(long) << " byte(s)" << endl;
    cout << "long long: " << sizeof(long long) << " byte(s)" << endl;
    cout << "float: " << sizeof(float) << " byte(s)" << endl;
    cout << "double: " << sizeof(double) << " byte(s)" << endl;
    cout << "long double: " << sizeof(long double) << " byte(s)" << endl;
    cout << "bool: " << sizeof(bool) << " byte(s)" << endl;

    // ======================================================
    // 5.15 EXEMPLOS EXTRAS
    // ======================================================
    cout << "\n=== EXEMPLOS EXTRAS ===" << endl;
    exConstSignedChar();
    exConstUnsignedChar();
    exConstChar();
    exVoidPointer();

    return 0;
}