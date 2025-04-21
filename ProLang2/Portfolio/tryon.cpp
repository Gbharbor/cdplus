#include <iostream>
using namespace std;

void fillArray(int* arr, int size){
   for(int i = 0; i < size; ++i) {
      cout<<"elemento: "<< i;
      cin>>arr[i];
   }
}
void printArray(const int* arr, int size){
   cout<<"\nValores do vetor: \n";
   for(int i = 0; i < size; ++i) {
      cout<<arr[i]<<" ";
   }
   cout<<endl;
}
int main() {
   int n;
   cout<<"tam do vetor: ";
   cin>>n;

   int* array = new(nothrow) int[n];
   if(!array){
      cerr<<"erro: falha na alocacao de memoria.\n";
      return 1;
   }
   fillArray(array, n);
   printArray(array, n);
   delete[] array;
   return 0;
}