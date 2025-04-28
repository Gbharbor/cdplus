#include <iostream>
using namespace std;

void power(int *number, int exponent) {
   int originalValue = *number;
   if(exponent == 0) {
      *number = 1;
      return;
   }
   for (int i = 2; i <= exponent; i++) {
      *number = *number * originalValue;
   }
}
int main () {
   int value = 9;
   power(&value, 0);
   cout<<"power result"<<value<<endl;
   return 0;
}