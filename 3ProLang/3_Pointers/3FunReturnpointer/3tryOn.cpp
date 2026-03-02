#include <iostream>;
using namespace std;

int main() {
   int number = 100;
   int* pointer = &number;
   int** pointerToPointer = &pointer;

   cout<<"value directly from the variable: "<<number<<endl;
   cout<<"value via pointer: "<<*pointer<<endl;
   cout<<"value via pointer to pointer"<<**pointerToPointer<<endl;

   cout<<"\nMemory Addresses: "<<endl;
   cout<<"address of number: "<<&number<<endl;
   cout<<"address of pointer: "<<pointer<<endl;
   cout<<"address of pointerToPointer"<<pointerToPointer<<endl;

   return 0;
}
// Value directly from the variable: 100
// Value via pointer: 100
// Value via pointer to pointer: 100

// Memory Addresses:
// Address of 'number': 0x7ffee2a48c1c
// Address of 'pointer': 0x7ffee2a48c1c
// Address of 'pointerToPointer': 0x7ffee2a48c20