#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ofstream escreva;
   escreva.open("texto.txt", ofstream::app);
   escreva<<"teste arquivo";
   escreva.close();

   ifstream ler;
   char conjunto[50];
   ler.open("texto.txt");
   if(ler.is_open()){
      while (ler.getline(conjunto, 50)){
         cout<<conjunto;
      }
   }
   return 0;
}
