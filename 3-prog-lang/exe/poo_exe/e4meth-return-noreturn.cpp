#include <iostream>
using namespace std;

class Calculator {
   public:
      int somar(int a, int b) {
         return a + b;
      }
   void showMessage() {
      cout<<"calculadora pronta para uso"<<endl;
   }
};
int main () {
   Calculator Calc;
   Calc.showMessage();
   cout<<"sum: "<<Calc.somar(6,6)<<endl;
}