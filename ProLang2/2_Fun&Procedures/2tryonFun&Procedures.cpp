#include <iostream>
#include <string>
using namespace std;

void writeMenu(){
   cout << "\n1 - Register";
   cout << "\n2 - List";
}

int calculateFactorial(int x) {
   int result = 1;
   while(x != 1) {
      result *= x;
      x--;
   }
   return result;
}

int sum(int a, int b) {
   return a + b;
}

float average(float a, float b) {
   return(a + b) / 2;
}

bool isEven(int num) {
   return num % 2 == 0;
}

char firstCharacter(string str) {
   return str[0];
}

int* findMaximum(int arr[], int size) {
   int* max = &arr[0];
   for (int i = 0; i < size; i++)
   {
      if(arr[i] > *max) {
         max = &arr[i];
      }
   }
   return max;
}

int& greaterNumber(int& a, int& b) {
   if(a > b) {
      return a;
   }
   return b;
}

struct Point {
   int x, y;
};
Point createPoint(int x, int y) {
   Point p = {x,y};
   return p;
}

class Person {
   public:
      string name;
      int age;

      Person(string name, int age) : name(name), age(age) {}
};
Person createPerson(string name, int age) {
   return Person(name, age);
}

std::string greeting() {
   return "hello";
}

void function1() {
   cout<<"hi im function 1";
}
void function2() {
   cout<<"hi um function 2";
}
void function3() {
   cout<<"hi, im function 3, & gonna call the functions 1&2"<<endl;
   function1();
   function2();
}
void globalFunction1();
void globalFunction2();
void globalFunction3();
int globalVariable = 100;
void globalFunction4() {
   cout<<"hi , im call function4"<<endl;
   cout<<"var global inside the function 4"<<globalVariable<<endl;
}
void globalFunction5();
void globalFunction3() {
   cout<<"hi im function3 , calling globalfunction1 & 2"<<endl;
   void globalFunction1();
   void globalFunction2();
}
void globalFunction5() {
   cout<<"hi im global function5"<<endl;
}

void doubleValue(int number) {
   number = number * 2;
   cout<<"Inside the function (for value)"<<number<<endl;
}

void doubleValueByReference(int* number) {
   *number = (*number) * 2;
   cout<<"inside the function (for reference)"<<*number<<endl;
}

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