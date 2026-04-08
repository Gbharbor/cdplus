//para ver o exemplo em POO, ex_POO.cpp
#include <iostream>
#include <string>

using namespace std;

void mostrarCarro (string modelo, int ano) {
   cout<<"modelo: ,"<<modelo<<", ano: "<<ano<<endl;
}
int main() {
   mostrarCarro("fusca", 1972);
   return 0;
};