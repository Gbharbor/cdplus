// ---------------------------------------------
// 2. Pointers in Functions: Pass by Reference
// ---------------------------------------------

// We can create functions that receive parameters in two ways:

// - By value: The function receives a copy of the variable's value. 
//   Any changes made inside the function do NOT affect the original value.

// - By reference: The function receives the address of the variable, 
//   meaning it can directly alter the original value of the variable.
//   This is done using pointers.

// >>> IMPORTANT: When passing by reference with pointers, the function can
// directly modify the original values, so caution is necessary.

// Example of a function with pass-by-reference using pointers:
// void sum(int *value1, int *value2) { ... }

// Remember:
// pointer = address of the variable
// *pointer = value stored at the address pointed to by the pointer

#include <iostream>
using namespace std;

// Function that calculates the power of a number, altering the original value
void power(int *number, int exponent) {
    int originalValue = *number; // Save the original value before modifications

    // If the exponent is zero, any number raised to 0 is 1
    if (exponent == 0) {
        *number = 1;
        return;
    }

    // Multiply the original value by itself (exponent - 1) times
    for (int i = 2; i <= exponent; i++) {
        *number = *number * originalValue;
    }
}

int main() {
    int value = 9;

    // Since the function expects a pointer, we pass the address of 'value' using the & operator
    power(&value, 0);

    // Print the result of the operation (value may have been changed by the function)
    cout << "Power result: " << value << endl;

    return 0;
}

// ---------------------------------------------
// 2.1 Pointers to Arrays and Matrices
// ---------------------------------------------

// Pointers can be used to access and manipulate elements of arrays and matrices.

// DEFINITION:
// A pointer can directly reference the elements of an array or matrix, 
// starting from the first element.

// PASSING PARAMETERS:
// When passing an array to a function, we are actually passing the address 
// of its first element. This allows modifying the original array inside the function.

// POINTER ARITHMETIC:
// - Incrementing a pointer moves it to the next element, based on the data type.
//   E.g., for int (4 bytes), pointer++ moves 4 bytes in memory.
// - The compiler takes care of the correct displacement calculation.
// - This allows sequentially accessing elements, just like using indices, 
//   but using only the pointer.

// BENEFITS:
// - Greater control over data manipulation.
// - More efficient memory usage.
// - Easier passing of arrays and matrices to functions without data copying.

#include <iostream>
using namespace std;

int main() {
    int array[5] = {20, 34, 58, 70, 125};   // Array with 5 elements
    int* pointer = array;                   // Pointer points to the first element of the array

    cout << "[Example 2.1] Pointers to Arrays\n";

    // Access the first element
    cout << *pointer << endl;

    // Move to the second element
    pointer++;
    cout << *pointer << endl;

    // Continue accessing the remaining elements using pointer arithmetic
    for (int i = 2; i < 5; i++) {
        pointer++;
        cout << *pointer << endl;
    }

    return 0;
}
// ---------------------------------------------
// 2.2 Array Sorting: Array vs Pointer
// ---------------------------------------------

#include <iostream>
using namespace std;

// Sort an array passed as a parameter (by value, using a regular array)
void sortArrayByValue(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
//índices de array (que no fundo são ponteiros, mas a sintaxe esconde isso).
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// Sort an array using a pointer
void sortWithPointer(int* ptr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
//dá mais controle sobre como os dados são acessados na memória.
            if (*(ptr + j) > *(ptr + j + 1)) {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
}

// Helper function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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