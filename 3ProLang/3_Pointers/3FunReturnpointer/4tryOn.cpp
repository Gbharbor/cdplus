#include <iostream>
using namespace std;
int main() {
   int* pointerToInteger = new int;
   *pointerToInteger = 50;

   cout<<"value stored in the pointer: "<<*pointerToInteger<<endl;
   cout<<"Allocated address: "<<pointerToInteger;
   delete pointerToInteger;

   int size = 5;
   int* array = new int[size];
   for(int i =0; i<size; i++) {
      array[i] = (i + 1) * 10;
   }

   cout<<"\nValue of the dynamically allocated array\n";
   for(int i = 0; i < size; i++) {
      cout<<array[i]<< " ";
   } cout<<endl;
   delete[] array;
   return 0;
}