#include <string> //for using string type
#include <iostream> //for standard input/output
/*
CONSTANTS IN C++
Constants are fixed values that cannot be changed after being defined.

type = const 
const keyword defines a constant that respects the rules of scope, ensuring
that its value cannot be changed any time.
*/
const double PI = 3.14159;
const int maxAge = 100;

//Type = constexpr
//The constexpr keyword is used for values that must be known and evaluated at compile time.
constexpr int square (int x) {
    return x * x;
};
constexpr int value = square (5); //Evaluated at compile time

//type = #DEFINE
//The define directive is a processor directive that creates macros.
//I is less safe because it does not respect scope and does not provide type checking.
#define max_size 100
int array[max_size];

//Literals
//Literals are fixed values that are directly placed in the code.
int age = 25; //integer literal
double rate = 4.5; //floating-point literal
char letter = 'B'; //character literal
// string name = "joao"; //String literal