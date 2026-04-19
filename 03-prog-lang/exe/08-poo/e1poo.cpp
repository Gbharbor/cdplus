#include <iostream>
using namespace std;

class carro { 
   public: 
      string modelo;
      int ano;
      void mostrarDetalhes() {
         cout<<"modelo: "<<modelo<<",ano: "<<ano<<endl;
      }
};
int main () {
   carro meuCarro;
   meuCarro.modelo = "fusca";
   meuCarro.ano = 1990;
   meuCarro.mostrarDetalhes();
   return 0;
};