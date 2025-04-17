// 1.4 Chamada de Funções
#include <iostream>
using namespace std;

// Funções que são declaradas no topo, mas podem ser chamadas em qualquer ordem dentro do código.
void funcao1() {
   cout << "Olá, sou a função 1\n";
}
void funcao2() {
   cout << "Olá, sou a função 2\n";
}
void funcao3() {
   cout << "Olá, sou a função 3 e chamo as funções 1 e 2\n";
   funcao1();  // Chama a função 1
   funcao2();  // Chama a função 2
}
int main() {
   funcao1();  // Chama a função 1
   funcao2();  // Chama a função 2
   funcao3();  // Chama a função 3, que por sua vez chama as funções 1 e 2
   return 0;
}

/////////////////////////////////////////

// Declaração de Funções Globais - As funções podem ser chamadas sem se preocupar com a ordem no código
#include <iostream>
using namespace std;
// Declaração das funções globais
void function1();
void function2();
void function3();
int main() {
   // Chama as funções definidas no topo
   function1();
   function2();
   function3();
   return 0;
}
void function3() {
   cout << "Olá, sou a função 3 e chamo as funções 1 e 2\n";
   function1();  // Chama a função 1
   function2();  // Chama a função 2
}
void function1() {
   cout << "Olá, sou a função 1\n";
}
void function2() {
   cout << "Olá, sou a função 2\n";
}

/////////////////////////////////////////

// Declaração e Uso de Variáveis Globais
#include <iostream>
using namespace std;
// Declaração de variável global
int variavelGlobal;
void function4() {
   cout << "Olá, sou a função 4\n";
}
int main() {
   // Declaração de variável local
   int variavelLocal;
   function4();  // Chama a função 4
   return 0;
}

/////////////////////////////////////////

// Exemplo de Função Local e Global
#include <iostream>
using namespace std;
// Declaração de função global
void funcao5();
int main() {
   // A função é chamada dentro de main, mas pode ser declarada fora
   funcao5();  // Chama a função 5
   return 0;
}
void funcao5() {
   cout << "Olá, sou uma função\n";
}
