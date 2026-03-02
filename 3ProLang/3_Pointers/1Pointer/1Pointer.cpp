// ---------------------------------------------
// 1. Pointers in C++
// ---------------------------------------------

// A pointer is a variable that stores the memory address of another variable.
// Instead of storing a value directly, it points to the location of that value in memory.
// A variable has 3 attributes (name, value, and address)


// ---------------------------------------------
// 1.1 Declaring Pointers
// ---------------------------------------------

// The declaration of a pointer is similar to that of a regular variable, 
// with the addition of an asterisk (*) to indicate it is a pointer.
// The syntax is: <type>* <pointerName>;
// Pointers can be of various types, including the void type (generic pointer).

#include <iostream>
using namespace std;

int main() {
    int value = 123;
    int* reference; // Pointer declaration

    // Assigning the address of 'value' to the pointer 'reference'
    reference = &value;

    cout << "\n[Example 1.1] Pointers - Declaring and Assigning\n";
    cout << "Value of the variable 'value': " << value << endl;
    cout << "Memory address stored in 'reference': " << reference << endl;

    // ---------------------------------------------
    // 1.2 Dereferencing a Pointer
    // ---------------------------------------------

    // Dereferencing a pointer means accessing the value stored at the memory address 
    // the pointer is pointing to. This is done using the * (dereferencing asterisk) operator.

    int anotherValue = 21;
    int* pointer;

    pointer = &anotherValue; // 'pointer' points to the address of 'anotherValue'

    cout << "\n[Example 1.2] Dereferencing a Pointer\n";
    cout << "Memory address pointed to by 'pointer': " << pointer << endl;
    cout << "Value stored at the address pointed to by 'pointer': " << *pointer << endl;

    // Modifying the value at the address pointed to by 'pointer'
    *pointer = 12345;

    cout << "New value stored at the address pointed to by 'pointer': " << *pointer << endl;

    return 0;
}