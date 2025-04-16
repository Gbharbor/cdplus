#include <stdio.h> // Input/output functions header from C. It works in C++, but it's not recommended since C++ has modern libraries.

int main() {
   int age;
   printf("Enter your age: ");
   scanf("%d", &age); // %d for integer value
   printf("You are %d years old.\n", age);
   return 0;
}