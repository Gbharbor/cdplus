// ===============================================================
// PROCEDIMENTOS, FUNÇÕES, TIPOS DE RETORNOS, CHAMADAS E PARÂMETROS
// ===============================================================

#include <iostream>
#include <string>
using namespace std;

// ---------------- Procedimentos ----------------

// Procedimento para exibir um menu
void writeMenu() {
    cout << "\n[Menu Options]";
    cout << "\n1 - Register";
    cout << "\n3 - Exit" << endl;
}

// ---------------- Funções Simples ----------------

// Função para calcular o fatorial de um número
//esse int x e o parametro que a funcao recebe
int calculateFactorial(int x) {
    int result = 1;  // Inicializa a variável 'result' com 1.
    while (x != 1) {  // Enquanto 'x' for diferente de 1, o loop vai continuar.
        result *= x;  // Multiplica o valor atual de 'result' por 'x'.
        x--;          // Decrementa 'x' em 1 (faz x = x - 1).
    }
    return result;    // Retorna o valor final de 'result', que será o fatorial de 'x'.
}

// ---------------- Tipos de Retorno ----------------

// Função que retorna um valor inteiro (int)
int sum(int a, int b) {
    return a + b;
}

// Função que retorna um valor de ponto flutuante (float)
float average(float a, float b) {
    return (a + b) / 2;
}

// Função que retorna um valor booleano (bool)
bool isEven(int num) {
    return num % 2 == 0;
}

// Função que retorna um caractere (char)
char firstCharacter(string str) {
    return str[0];
}

// Função que retorna um ponteiro (int*)
int* findMaximum(int arr[], int size) {
    int* max = &arr[0];  // Inicializa 'max' como o endereço do primeiro elemento do array.
    for (int i = 1; i < size; i++) {  // Laço começa do segundo elemento (i = 1).
        if (arr[i] > *max) {  // Se o valor de arr[i] for maior que o valor apontado por 'max'
            max = &arr[i];  // Atualiza 'max' para apontar para o novo maior valor.
        }
    }
    return max;  // Retorna o ponteiro 'max', que aponta para o maior valor do array.
}

// Função que retorna uma referência (int&)
int& greaterNumber(int& a, int& b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Estrutura para representar um ponto (struct)
struct Point {
    int x, y;
};

// Função que retorna uma estrutura (struct)
Point createPoint(int x, int y) {
    Point p = {x, y};
    return p;
}

// Classe para representar uma pessoa
class Person {
public:
    string name;
    int age;

    Person(string name, int age) : name(name), age(age) {}
};

// Função que retorna um objeto de classe
Person createPerson(string name, int age) {
    return Person(name, age);
}

// Função que retorna uma string (std::string)
std::string greeting() {
    return "Olá, bem-vindo ao C++!";
}

// ---------------- 1.4 Chamada de Funções ----------------

// Funções declaradas no topo e chamadas em qualquer ordem
void function1() {
    cout << "Olá, sou a função 1" << endl;
}
void function2() {
    cout << "Olá, sou a função 2" << endl;
}
void function3() {
    cout << "Olá, sou a função 3 e vou chamar a função 1 e 2:" << endl;
    function1();
    function2();
}

// ---------------- Declaração de Funções Globais ----------------

void globalFunction1();
void globalFunction2();
void globalFunction3();

// Variáveis globais
int globalVariable = 100;

// Função utilizando variável global
void globalFunction4() {
    cout << "Olá, sou a função 4" << endl;
    cout << "Variável global dentro da função 4: " << globalVariable << endl;
}

// Função global exemplo
void globalFunction5();

void globalFunction3() {
    cout << "Olá, sou a função 3 e também vou chamar globalFunction1 e globalFunction2:" << endl;
    globalFunction1();
    globalFunction2();
}
void globalFunction1() {
    cout << "Olá, sou a função 1 (global)" << endl;
}
void globalFunction2() {
    cout << "Olá, sou a função 2 (global)" << endl;
}
void globalFunction5() {
    cout << "Olá, sou a função 5" << endl;
}

// ---------------- Parâmetros por Valor e por Referência ----------------

// Função que recebe parâmetro por valor (não altera o original)
void doubleValue(int number) {
    number = number * 2;
    cout << "Dentro da função (por valor): " << number << endl;
}

// Função que recebe parâmetro por referência (modifica o original)
void doubleValueByReference(int* number) {
    *number = (*number) * 2;
    cout << "Dentro da função (por referência): " << *number << endl;
}

// ---------------- MAIN ----------------

int main() {
    cout << "\n=== Testando Procedimento ===" << endl;
    writeMenu();

    cout << "\n=== Testando Função com Retorno ===" << endl;
    int factorial = calculateFactorial(5);
    cout << "Fatorial de 5: " << factorial << endl;

    cout << "\n=== Testando Tipos de Retornos ===" << endl;
    cout << "Soma: " << sum(10, 5) << endl;
    cout << "Média: " << average(5.0, 7.0) << endl;
    cout << "6 é par? " << (isEven(6) ? "Sim" : "Não") << endl;
    cout << "Primeiro caractere: " << firstCharacter("Hello") << endl;

    int arr[] = {1, 2, 3, 9, 5};
    int* maximum = findMaximum(arr, 5);
    cout << "Maior número no array: " << *maximum << endl;

    int a = 10, b = 20;
    int& greater = greaterNumber(a, b);
    cout << "Maior número entre a e b: " << greater << endl;

    Point p = createPoint(3, 4);
    cout << "Ponto criado: (" << p.x << ", " << p.y << ")" << endl;

    Person person = createPerson("Carlos", 25);
    cout << "Pessoa criada: " << person.name << ", Idade: " << person.age << endl;

    cout << greeting() << endl;

    cout << "\n=== Testando Chamada de Funções (Diretas) ===" << endl;
    function1();
    function2();
    function3();

    cout << "\n=== Testando Chamada de Funções Globais ===" << endl;
    globalFunction1();
    globalFunction2();
    globalFunction3();

    cout << "\n=== Testando Variáveis Globais ===" << endl;
    globalFunction4();

    cout << "\n=== Testando Função Global Localizada ===" << endl;
    globalFunction5();

    cout << "\n=== Testando Parâmetro por Valor ===" << endl;
    int value1 = 10;
    cout << "Antes da função (por valor): " << value1 << endl;
    doubleValue(value1);
    cout << "Depois da função (por valor): " << value1 << endl;

    cout << "\n=== Testando Parâmetro por Referência (Ponteiro) ===" << endl;
    int value2 = 10;
    cout << "Antes da função (por referência): " << value2 << endl;
    doubleValueByReference(&value2);
    cout << "Depois da função (por referência): " << value2 << endl;

    return 0;
}