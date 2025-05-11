#include <iostream>
using namespace std;

void troca_ponteiros(int *n1, int *n2) {
   int aux = *n1;
   *n1 = *n2;
   *n2 = aux;
}
int main() {
   int valor = 10;
   cout<<"Endereco da variavel valor: "<< &valor<<endl;

   int *ptr = nullptr; //inicialmente nulo
   ptr = &valor; //aponta para a var valor
   cout<<"valor acessado por ponteiros: "<<*ptr<<endl;

   *ptr = 20;
   cout<<"novo valor da variavel valor(modificado via ponteiro)"<<valor<<endl;

   int *dinamico = new int;
   *dinamico = 50;
   cout<<"valor alocado dinamicamente:"<<*dinamico<<endl;

   delete dinamico; //deslocando memoria

   int a = 5, b = 8;
   cout<<"antes da troca: a -> "<<a<<", b -> "<<b<<endl;
   troca_ponteiros(&a, &b);
   cout<<"depois da troca: a -> "<<a<<", b -> "<<b<<endl;
   return 0;
}