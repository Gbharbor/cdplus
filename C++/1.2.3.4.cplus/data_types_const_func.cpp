#include <iostream>
#include <string>
#include <cstdio>       // Para o tipo C
#include <iomanip>      // Biblioteca para manipulação de formato
#include <limits>       // Biblioteca para verificar os limites dos tipos de dados

// Bibliotecas C
extern "C" {
    #include <stdio.h>  // Equivalente a cstdio
    #include <stdlib.h> // Alocação de memória, controle, conversão em C
    #include <string.h> // Manipulação de string em C
}

using namespace std;

// Constantes e definições
const double PI = 3.141592653589793;          // Precisão aumentada de PI
const int maxAge = 100;                       // Máxima idade
constexpr int square(int x) { return x * x; } // Função constexpr para cálculo de quadrado
constexpr int value = square(5);              // Valor calculado em tempo de compilação

#define max_size 100                            // Definição de tamanho máximo para o array

// Variáveis globais
int age = 25;
float height = 1.75;
char letter = 'B';
char initial = 'A';
string name = "Joao";
double rate = 4.5;
bool isApproved = true;

// Tipos de variáveis
int numbers[5] = {1, 2, 3, 4, 5};
signed int signedNumber = -100;
unsigned int unsignedNumber = 100;
short int smallN = 3200;
int standardN = 100000;
long int largeN = 1000000000; 
long long int veryLargeN = 10000000000000000; // Número muito grande para long long

// Struct para armazenar informações de uma pessoa
struct Person {
    string name;
    int age;
    float height;
};

// Função para exibir uma mensagem
void displayMessage() {
    cout << "Essa funcao nao retorna nada por ser void" << endl;
}

// Funções demonstrativas de uso de tipos de dados
void exConstSignedChar() {
    const signed char sc = -120;  // signed char constante com valor fixo (-120)
    cout << "Valor de const signed char: " << static_cast<int>(sc) << endl; // Exibe: -120
}

void exConstUnsignedChar() {
    const unsigned char uc = 200; // unsigned char constante, somente valores positivos
    cout << "Valor de const unsigned char: " << static_cast<int>(uc) << endl; // Exibe: 200
}

void exConstChar() {
    const char letra = 'A'; // Constante de caractere (código ASCII 65)
    cout << "Valor de const char: " << letra << endl; // Exibe: A
}

void exVoidPointer() {
    int num = 42;
    void* ptr = &num;  // Ponteiro genérico void* que armazena o endereço de num
    cout << "Valor de num via void*: " << *(static_cast<int*>(ptr)) << endl; // Exibe: 42
}

// Função principal do programa
int main() {
    // Saudações
    cout << "Hello World" << endl;
    std::cout << "Hello World (sem using namespace std)" << std::endl;
    printf("Hello\n\t\aWorld (usando printf)\n");

    // Exibindo constantes e literais
    cout << "\nConstantes e Literais: " << endl;
    cout << "Número PI: " << PI << endl;
    cout << "MaxAge: " << maxAge << endl;
    cout << "Valor calculado em tempo de compilação (constexpr): " << value << endl;
    cout << "Tamanho máximo do array (#define): " << max_size << endl;

    // Exibindo variáveis básicas
    cout << "\nVariáveis Básicas: " << endl;
    cout << "Idade: " << age << endl;
    cout << "Taxa: " << rate << endl;
    cout << "Altura: " << height << endl;
    cout << "Letra: " << letter << endl;
    cout << "Inicial: " << initial << endl;
    cout << "Nome: " << name << endl;
    cout << "Aprovado: " << (isApproved ? "Sim" : "Não") << endl;

    // Exibindo o array
    cout << "\nNúmeros no Array: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    // Criando e exibindo uma struct
    Person person;
    person.name = "Joao";
    person.age = 30;
    person.height = 1.82;
    cout << "Pessoa - Nome: " << person.name << ", Idade: " << person.age << ", Altura: " << person.height << endl;

    // Exibindo variáveis com tipos assinados e não assinados
    cout << "\nNúmero assinado (< 0): " << signedNumber << endl;
    cout << "Número não assinado (> 0): " << unsignedNumber << endl;

    // Exibindo variáveis de diferentes tamanhos
    cout << "\nVariáveis de Diferentes Tamanhos: " << endl;
    cout << "Número pequeno (short): " << smallN << endl;
    cout << "Número padrão (int): " << standardN << endl;
    cout << "Número grande (long): " << largeN << endl;
    cout << "Número muito grande (long long): " << veryLargeN << endl;

    // Chamando a função que exibe uma mensagem
    displayMessage();

    // Entradas e saídas com variáveis
    int idade;
    cout << "\nDigite sua idade: ";
    cin >> idade;
    cout << "Você tem " << idade << " anos." << endl;

    string nome;
    cout << "Digite o seu nome: ";
    cin >> nome;
    cout << "Olá, " << nome << ". Você tem " << idade << " anos." << endl;

    cin.ignore(); //Ignora o caractere de nova linha deixado pelo último cin
    string full_name;
    cout<<"Digite seu nome completo: ";
    getline(cin, full_name); // Lê uma linha inteira de texto (incluindo espaços) e armazena na variável full_name
    cout<<"Ola, "<<full_name<<"!"<<endl;

    // Leitura de uma matriz de caracteres
    char matriz[60];
    cout << "Digite até 49 caracteres: ";
    cin.getline(matriz, 50);
    cout << "Você digitou: " << matriz << endl;

    // Base numérica (hexadecimal)
    int numero = 10;
    cout << "Número em hexadecimal: " << hex << numero << endl;

    //formatacao de numeros reais
    double pi = 3.14159;
    cout<<"Numero em ponto fixo: "<<fixed<<pi<<endl; //somente fixed aparece 6 numeros, mas pode determinar com setprecision
    cout<<"numero em notacao cientifica: "<<scientific<<pi<<endl;

    // Precisão de variáveis reais
    cout.precision(3);
    cout << fixed << "Número com precisão de 3 casas: " << pi << endl;

    // Exemplo de Espaçamento, Preenchimento e Alinhamento
    cout << "\nEspaçamento, Preenchimento e Alinhamento: " << endl;

    // Alinhamento à direita e preenchimento com espaços (padrão)
    cout << "Número com largura mínima de 5 (direita): ";
    cout << right;  // Alinha à direita
    cout.width(5);  // Largura mínima de 5
    cout << 10 << endl;  // Exibe '   10'

    // Alinhamento à esquerda e preenchimento com '0'
    cout << "Número com largura mínima de 8 (esquerda, preenchido com 0): ";
    cout.fill('0');  // Preenche com '0'
    cout.width(8);   // Largura mínima de 8
    cout << 10 << endl; // Exibe '10000000'

    // Alinhamento à esquerda e preenchimento com espaços (padrão)
    cout << "Número com largura mínima de 8 (esquerda, preenchido com espaços): ";
    cout.fill(' ');  // Preenche com espaços
    cout.width(8);   // Largura mínima de 8
    cout << left << 10 << endl;  // Exibe '10      '

   // Tamanhos de Tipos de Dados
    cout<<"\nTamanhos de Tipos de Dados:"<<endl;
    cout<<"char: "<<sizeof(char)<<" byte"<<"//Geralmente 1 byte"<<endl;
    cout<<"signed char: "<<sizeof(signed char)<<" byte"<<"//Geralmente 1 byte"<<endl;
    cout<<"unsigned char: "<<sizeof(unsigned char)<<" byte"<<"//Geralmente 1 byte" <<endl;
    cout<<"short: "<<sizeof(short)<<" bytes"<<"//Geralmente 2 bytes"<<endl;
    cout<<"int: "<<sizeof(int)<<" bytes"<<"//Geralmente 4 bytes"<<endl;
    cout<<"long: "<<sizeof(long)<<" bytes"<<"//Geralmente 4 bytes em sistemas de 32 bits, 8 bytes em sistemas de 64 bits"<<endl;
    cout<<"long long: "<<sizeof(long long)<<" bytes"<<"//Geralmente 8 bytes" <<endl;
    cout<<"float: "<<sizeof(float)<<" bytes"<<"//Geralmente 4 bytes" <<endl;
    cout<<"double: "<<sizeof(double)<<" bytes"<<"//Geralmente 8 bytes"<<endl;
    cout<<"long double: "<<sizeof(long double)<<" bytes"<<"//Geralmente 16 bytes em sistemas modernos" <<endl;
    
    // Chamando funções de demonstração
    exConstSignedChar();
    exConstUnsignedChar();
    exConstChar();
    displayMessage();
    exVoidPointer();

    return 0;
}