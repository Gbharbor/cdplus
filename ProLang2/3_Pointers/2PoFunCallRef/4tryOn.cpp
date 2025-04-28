#include <iostream>
using namespace std;

void sortArrayByValue(int arr[], int size) {
   for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
         if(arr[j]>arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
}


void sortWithPointer(int* ptr, int size) {
   for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i -1; j++) {
         if(*(ptr + j)>*(ptr + j + 1)) {
            int temp = *(ptr + j);
            *(ptr+j) = *(ptr + j + 1);
            *(ptr+j+1) = temp;
         }
      }
   }
}
void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++) {
      cout<<arr[i]<<" ";
   }  cout<<endl;
}
int main() {
   int array1[5] = {50, 10, 30, 20, 40};
   int array2[5] = {50, 10, 30, 20, 40};
   cout << "[Before Sorting]\n";
   cout << "Array by value: ";
   printArray(array1, 5);
   cout << "Array with pointer: ";
   printArray(array2, 5);

   sortArrayByValue(array1, 5);
   sortWithPointer(array2, 5);

   cout << "\n[After Sorting]\n";
   cout << "Array by value: ";
   printArray(array1, 5);
   cout << "Array with pointer: ";
   printArray(array2, 5);

   return 0;
}