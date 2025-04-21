#include <iostream>
#include <new>

using namespace std;

int globalVar = 10;

void showScopeEx() {
   int localVar = 5;
   cout<<"var local: "<<localVar<<endl;
}

int main() {
   cout<<"-1.Escopo de Variaveis-"<<endl;
   cout<<"exibe a var global: "<<globalVar<<endl;
   showScopeEx();

   cout<<"\n-2.Alocacao dinamica c/ tam definido pelo user"<<endl;
   int size; 
   cout<<"Digite o numero d elementos: ";
   cin>>size;
   int* vector = new int[size];

   for(int i = 0; i < size; i++) {
      vector[i] = i * 10;
      cout<<vector[i]<<" ";
   }
   cout<<endl;
   delete[] vector;

   cout<<"-3.Estatica vs Dinamica"<<endl;
   int staticVar = 100;
   int* dynamicVar = new int(200);

   cout<<"Estatica - valor: "<<staticVar<<endl;
   cout<<"Dinamica - valor: "<<*dynamicVar<<endl;
   delete dynamicVar;

   cout<<"-4.Operadores new&delete"<<endl;
   int* number = new int(42);
   cout<<"valor alocado com new: "<<*number<<endl;
   delete number;

   cout<<"-5.Alocacao de Array com new[]"<<endl;
   int* array = new int[5];
   for(int i = 0; i < 5; i++){
      array[i] = i + 1;
      cout<<array[i]<<" ";
   }
   cout<<endl;

   cout<<"-6.Esgotamento de Memoria(simulacao)"<<endl;
   long long bigSize = 1e12;
   int* pointer = new(nothrow) int[bigSize];

   if(!pointer){
      cout<<"erro: falha na alocacao de memoria"<<endl;
   } else {
      cout<<"memoria alocada com sucesso"<<endl;
      delete[] pointer;
   }
   return 0;
}