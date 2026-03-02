// ---------------------------------------------
// 3. Functions that Return Pointers
// ---------------------------------------------

// In C++, we cannot return arrays or matrices directly from a function,
// because arrays cannot be returned by value like regular variables.

// However, we can work around this by using pointers. Since pointers
// can store the address of an array (or a matrix), it is possible
// to return a pointer pointing to a memory area containing the desired data.

// DECLARATION EXAMPLE:
// int* calculateArray();   -> function returning a pointer to int
// char* uppercase();       -> function returning a pointer to char

// That is, we can return the address of an array, which will be valid
// if it is declared as static within the function or dynamically allocated.

// WARNING:
// The returned array should not be a local (non-static) variable, as
// it will be destroyed when the function scope is exited. This would cause undefined behavior.

// Safe alternatives:
// - Use `static` arrays within the function
// - Use `new` for dynamic allocation and free with `delete[]`
// - Pass the array as a parameter and modify it by reference

// ---------------------------------------------
// 3.1 Function Pointers
// ---------------------------------------------

// A function pointer stores the ADDRESS of a function,
// allowing us to call it indirectly or pass it as a parameter.

// Syntax:
// <returnType> (*pointerName)(parameters);

// Example:
// int (*functionPointer)();  // pointer to a function that returns int and takes no arguments

#include <iostream>
using namespace std;

// Simple function
int greeting() {
    cout << "Hello! This function was called through a pointer!" << endl;
    return 0;
}

// Another function for testing
int farewell() {
    cout << "Goodbye! I was also called via a pointer!" << endl;
    return 1;
}

int main() {
    // Declare a pointer to a function that returns int and takes no parameters
    int (*functionPointer)();

    // Assign the address of the 'greeting' function to the pointer
    functionPointer = greeting;

    // Call the function through the pointer
    functionPointer();

    // Now change to point to the 'farewell' function
    functionPointer = farewell;
    functionPointer();  // Call the new function via pointer

    return 0;
}

// ---------------------------------------------
// 3.2 Pointers to Pointers (int**)
// ---------------------------------------------

// In the previous sections, we saw that pointers store addresses of variables.
// But it is also possible for a pointer to point to another pointer.

// This is useful, for example, in dynamic memory allocation for matrices,
// passing pointers by reference, and manipulating data at deeper levels.

// ✅ DECLARATION EXAMPLE:
// int number = 512;
// int* pointerToInt = &number;         // pointer to int
// int** pointerToPointer = &pointerToInt;   // pointer to pointer to int

// Using the dereference operator:
// *pointerToInt   -> accesses the value of the variable 'number'
// *pointerToPointer  -> accesses the value of 'pointerToInt', which is the address of 'number'
// **pointerToPointer -> accesses the value stored at the address of 'number'

#include <iostream>
using namespace std;

int main() {
    // Declare an integer variable
    int number = 100;

    // Declare a pointer to the 'number' variable (pointer to int)
    int* pointer = &number;

    // Declare a pointer to the pointer 'pointer' (pointer to pointer)
    int** pointerToPointer = &pointer;

    // Accessing the value directly from the 'number' variable
    cout << "Value directly from the variable: " << number << endl;

    // Accessing the value through a pointer
    cout << "Value via pointer: " << *pointer << endl;

    // Accessing the value through a pointer to pointer
    cout << "Value via pointer to pointer: " << **pointerToPointer << endl;

    // Showing the memory addresses
    cout << "\nMemory Addresses:" << endl;

    // Address of 'number'
    cout << "Address of 'number': " << &number << endl;

    // Address of 'pointer' (which stores the address of 'number')
    cout << "Address of 'pointer': " << pointer << endl;

    // Address of 'pointerToPointer' (which stores the address of 'pointer')
    cout << "Address of 'pointerToPointer': " << pointerToPointer << endl;

    return 0;
}
// Value directly from the variable: 100
// Value via pointer: 100
// Value via pointer to pointer: 100

// Memory Addresses:
// Address of 'number': 0x7ffee2a48c1c
// Address of 'pointer': 0x7ffee2a48c1c
// Address of 'pointerToPointer': 0x7ffee2a48c20
#include <iostream>
using namespace std;

int main() {
    // ---------------------------------------------
    // 3.3. The 'new' and 'delete' Operators
    // ---------------------------------------------

    // The 'new' operator is used to dynamically allocate memory.
    // It returns the allocated memory address, which can be stored in a pointer.

    // Example: Dynamically allocating an integer
    int* pointerToInteger = new int; // allocates memory for an integer

    // Assign a value to this allocated space
    *pointerToInteger = 50;

    cout << "Value stored in the pointer: " << *pointerToInteger << endl;
    cout << "Allocated address: " << pointerToInteger << endl;

    // When the memory allocated with 'new' is no longer needed, it should be freed using 'delete'
    delete pointerToInteger; // frees the allocated space to avoid memory leak

    // ---------------------------------------------------
    // We can also use 'new' to allocate arrays (vectors)
    // ---------------------------------------------------

    int size = 5;

    // Dynamically allocating an array of 5 integers
    int* array = new int[size];

    // Filling the array with values
    for (int i = 0; i < size; i++) {
        array[i] = (i + 1) * 10; // assigns 10, 20, 30, ...
    }

    // Displaying the values of the dynamically allocated array
    cout << "\nValues of the dynamically allocated array:\n";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Freeing the allocated memory for the array
    delete[] array; // we use delete[] for arrays

    return 0;
}