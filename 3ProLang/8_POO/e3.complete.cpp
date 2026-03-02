#include <iostream>
using namespace std;

class ContaBancaria {
   private:
      double saldo;
   public:
      ContaBancaria() { 
         saldo = 0;
      }
      void depositar(double valor) {
         if(valor > 0) {
            saldo += valor;
         }
      }
      double obterSaldo() {
         return saldo;
      }
};
int main () {
   ContaBancaria minhaConta;
   minhaConta.depositar(500);
   cout<<"saldo: "<<minhaConta.obterSaldo()<<endl;
   return 0;
}