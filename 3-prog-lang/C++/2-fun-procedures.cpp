// ===============================================================
// PROCEDIMENTOS, FUNÇÕES, TIPOS DE RETORNO, CHAMADAS E PARÂMETROS
// ===============================================================

#include <iostream>
#include <string>

using namespace std;

// ---------------------------------------------------------------
// 1. PROCEDIMENTOS
// ---------------------------------------------------------------

// Procedimento para exibir um menu.
// Procedimentos não retornam valores (void).
void writeMenu() {
   cout << "\n[Menu Options]";
   cout << "\n1 - Register";
   cout << "\n3 - Exit" << endl;
}


// ---------------------------------------------------------------
// 2. FUNÇÕES SIMPLES
// ---------------------------------------------------------------

// Função que calcula o fatorial de um número.
// O parâmetro "x" é o número recebido pela função.
int calculateFactorial(int x) {

   int result = 1;

   // Enquanto x for diferente de 1
   while (x != 1) {
      result *= x; // result = result * x
      x--;         // x = x - 1
   }

   return result; // retorna o fatorial calculado
}


// ---------------------------------------------------------------
// 3. DIFERENTES TIPOS DE RETORNO
// ---------------------------------------------------------------

// Função que retorna um inteiro
int sum(int a, int b) {
   return a + b;
}

// Função que retorna um número decimal
float average(float a, float b) {
   return (a + b) / 2;
}

// Função que retorna verdadeiro ou falso
bool isEven(int num) {
   return num % 2 == 0;
}

// Função que retorna um caractere
char firstCharacter(string str) {
   return str[0];
}


// ---------------------------------------------------------------
// 4. FUNÇÃO QUE RETORNA PONTEIRO
// ---------------------------------------------------------------

int* findMaximum(int arr[], int size) {

   int* max = &arr[0]; // endereço do primeiro elemento

   for (int i = 1; i < size; i++) {

      if (arr[i] > *max) {
         max = &arr[i]; // atualiza o ponteiro para o maior valor
      }
   }

   return max;
}


// ---------------------------------------------------------------
// 5. FUNÇÃO QUE RETORNA REFERÊNCIA
// ---------------------------------------------------------------

int& greaterNumber(int& a, int& b) {

   if (a > b) {
      return a;
   }

   return b;
}


// ---------------------------------------------------------------
// 6. RETORNANDO UMA STRUCT
// ---------------------------------------------------------------

struct Point {
   int x, y;
};

Point createPoint(int x, int y) {

   Point p = {x, y};

   return p;
}


// ---------------------------------------------------------------
// 7. RETORNANDO OBJETO DE CLASSE
// ---------------------------------------------------------------

class Person {
public:

   string name;
   int age;

   // Construtor da classe
   Person(string name, int age) : name(name), age(age) {}
};

Person createPerson(string name, int age) {

   return Person(name, age);
}


// ---------------------------------------------------------------
// 8. FUNÇÃO QUE RETORNA STRING
// ---------------------------------------------------------------

string greeting() {

   return "Olá, bem-vindo ao C++!";
}


// ---------------------------------------------------------------
// 9. CHAMADAS DE FUNÇÕES
// ---------------------------------------------------------------

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


// ---------------------------------------------------------------
// 10. FUNÇÕES GLOBAIS
// ---------------------------------------------------------------

void globalFunction1();
void globalFunction2();
void globalFunction3();

// variável global
int globalVariable = 100;

void globalFunction4() {

   cout << "Olá, sou a função 4" << endl;

   cout << "Variável global dentro da função 4: "
        << globalVariable << endl;
}

void globalFunction5();

void globalFunction3() {

   cout << "Olá, sou a função 3 e vou chamar globalFunction1 e globalFunction2:" << endl;

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


// ---------------------------------------------------------------
// 11. PARÂMETROS POR VALOR E POR REFERÊNCIA
// ---------------------------------------------------------------

// Parâmetro por valor (não altera o valor original)
void doubleValue(int number) {

   number = number * 2;

   cout << "Dentro da função (por valor): "
        << number << endl;
}


// Parâmetro por referência usando ponteiro
void doubleValueByReference(int* number) {

   *number = (*number) * 2;

   cout << "Dentro da função (por referência): "
        << *number << endl;
}


// ---------------------------------------------------------------
// FUNÇÃO PRINCIPAL
// ---------------------------------------------------------------

int main() {

   cout << "\n=== Testando Procedimento ===" << endl;
   writeMenu();

   cout << "\n=== Testando Função com Retorno ===" << endl;

   int factorial = calculateFactorial(5);

   cout << "Fatorial de 5: " << factorial << endl;


   cout << "\n=== Testando Tipos de Retorno ===" << endl;

   cout << "Soma: " << sum(10, 5) << endl;

   cout << "Média: " << average(5.0, 7.0) << endl;

   cout << "6 é par? "
        << (isEven(6) ? "Sim" : "Não") << endl;

   cout << "Primeiro caractere: "
        << firstCharacter("Hello") << endl;


   int arr[] = {1, 2, 3, 9, 5};

   int* maximum = findMaximum(arr, 5);

   cout << "Maior número no array: "
        << *maximum << endl;


   int a = 10, b = 20;

   int& greater = greaterNumber(a, b);

   cout << "Maior número entre a e b: "
        << greater << endl;


   Point p = createPoint(3, 4);

   cout << "Ponto criado: ("
        << p.x << ", "
        << p.y << ")" << endl;


   Person person = createPerson("Carlos", 25);

   cout << "Pessoa criada: "
        << person.name
        << ", Idade: "
        << person.age << endl;


   cout << greeting() << endl;


   cout << "\n=== Testando Chamadas de Funções ===" << endl;

   function1();
   function2();
   function3();


   cout << "\n=== Testando Funções Globais ===" << endl;

   globalFunction1();
   globalFunction2();
   globalFunction3();


   cout << "\n=== Testando Variável Global ===" << endl;

   globalFunction4();


   cout << "\n=== Testando Função Global ===" << endl;

   globalFunction5();


   cout << "\n=== Parâmetro por Valor ===" << endl;

   int value1 = 10;

   cout << "Antes da função: " << value1 << endl;

   doubleValue(value1);

   cout << "Depois da função: " << value1 << endl;


   cout << "\n=== Parâmetro por Referência ===" << endl;

   int value2 = 10;

   cout << "Antes da função: " << value2 << endl;

   doubleValueByReference(&value2);

   cout << "Depois da função: " << value2 << endl;

   return 0;
}