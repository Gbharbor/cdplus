#include <iostream> // Para entrada e saída padrão
#include <string>   // Para usar o tipo string

/*
VARIÁVEIS EM C++
Uma variável em C++ é um espaço na memória que armazena um valor e é identificada por um nome.
Para usar uma variável, você precisa definir seu tipo de dado (como int, float, char, etc.), 
que indica que tipo de informação a variável pode conter.
*/
int age = 25;               // Armazena um valor inteiro
float height = 1.75;        // Armazena um valor de ponto flutuante
char initial = 'A';         // Armazena um caractere

/*
RESERVANDO MEMÓRIA
Cada variável ocupa uma quantidade específica de memória. A memória em C++ é medida em bytes (cada byte pode ser pensado como um "cubículo" de armazenamento).
O tipo de dado de uma variável determina quantos bytes ela ocupará na memória.
*/
double pi = 3.141592653589793; // Mais preciso que float
bool isApproved = true;        // Armazena um valor booleano

/*
TIPOS DE DADOS ESTRUTURADOS
Array: Uma coleção de elementos do mesmo tipo, acessados por um índice.
*/
int numbers[5] = {1, 2, 3, 4, 5}; // Array de inteiros

/*
TIPOS DE DADOS ESTRUTURADOS
Struct e Class: Permitem agrupar diferentes tipos de dados sob o mesmo nome, criando novas estruturas.
*/
struct Person {
    std::string name;  // Armazena o nome da pessoa
    int age;           // Armazena a idade da pessoa
    float height;      // Armazena a altura da pessoa
};

/*
VOID
O tipo void é usado para indicar que uma função não retorna nenhum valor.
Não é utilizado para armazenar variáveis.
*/
void displayMessage() {
    std::cout << "Hello, world!" << std::endl; // Exibe uma mensagem
}

/*
TIPOS ASSINADOS E NÃO ASSINADOS
*/
signed int signedNumber = -100;    // Pode ser negativo ou positivo
unsigned int unsignedNumber = 200; // Apenas positivo

/*
INT, SHORT, LONG, LONG LONG
Escolher o tipo de dado apropriado ajuda a otimizar o uso de memória e o desempenho do programa.
*/
short int smallNum = 32000;                  // Para valores pequenos
int standardNumber = 100000;                 // Para valores comuns
long int largeNumber = 1000000000;           // Para valores grandes
long long int veryLargeNumber = 1000000000000; // Para valores enormes

int main() {
    // Exibindo variáveis básicas
    std::cout << "Idade: " << age << std::endl;
    std::cout << "Altura: " << height << std::endl;
    std::cout << "Inicial: " << initial << std::endl;
    std::cout << "Pi: " << pi << std::endl;
    std::cout << "Aprovado: " << (isApproved ? "Sim" : "Não") << std::endl;

    // Exibindo o array
    std::cout << "Números no array: ";
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Criando e exibindo uma struct
    Person person;
    person.name = "Joao";
    person.age = 30;
    person.height = 1.82;
    std::cout << "Pessoa - Nome: " << person.name << ", Idade: " << person.age << ", Altura: " << person.height << std::endl;

    // Exibindo variáveis com tipos assinados e não assinados
    std::cout << "Número assinado: " << signedNumber << std::endl;
    std::cout << "Número não assinado: " << unsignedNumber << std::endl;

    // Exibindo variáveis de diferentes tamanhos
    std::cout << "Número pequeno (short): " << smallNum << std::endl;
    std::cout << "Número padrão (int): " << standardNumber << std::endl;
    std::cout << "Número grande (long): " << largeNumber << std::endl;
    std::cout << "Número muito grande (long long): " << veryLargeNumber << std::endl;

    // Chamando a função que exibe uma mensagem
    displayMessage();

    return 0; // Indica que o programa foi concluído com sucesso
}