#include <iostream>
using namespace std;
int main() {
   int value = 123;
   int* reference;
   reference = &value;

   cout << "\n[Example 1.1] Pointers - Declaring and Assigning\n";
   cout<<"value of the var 'value: "<<value<<endl;
   cout<<"memory address stored in 'reference'"<<reference<<endl;

   int anotherValue = 21;
   int* pointer;

   pointer = &anotherValue;
   cout<<"\n[Example 1.2] Dereferencing a Pointer\n";
   cout<<"memory address pointed to by 'pointer': "<<pointer<<endl;
   cout<<"value stored at the address ponted to by 'pointer': "<<*pointer<<endl;
  
   *pointer = 12345;
   cout<<"new value stored at the address pointed to by 'pointer': "<<*pointer<<endl;
   return 0;
}