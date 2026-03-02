#include <iostream>
using namespace std;
int main() {
   int array[5] = {20, 34, 58, 70, 125};
   int* pointer = array;
 
   cout<< "[Example 2.1] Pointers to Arrays\n";
   cout<<*pointer<<endl;
   pointer++;
   cout<<*pointer<<endl;

   for (int i = 2; i < 5; i++) {
      pointer++;
      cout<<*pointer<<endl;
   }
   
   return 0;
}