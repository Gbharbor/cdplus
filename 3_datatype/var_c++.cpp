#include <string> //for using string type
#include <iostream> //for standard input/output

/*
VARIABLES IN C++
A variable in C++ is a space in memory that stores a value and is identified bya name.
To use a variable, you need to define its data type (such as int,float,char,etc.), which indicates what kind of information the variable can hold.

*/
int age = 25; // stires an integer value
float height = 1.75; //stores a floating point value
char initial = 'A';   //stores a character

/*
RESERVING MEMORY
Each variable occupies a specific amount of memory. Memory in c++ is measured in bytes (each byte can be thought of as a "cubicle" of storage).
The data type of a variable determines how many bytes it will occupy in memory.
*/
double pi = 3.141592653589793; // More precise than float
int age = 25;
float height = 1.75;
char initial = 'A';
bool isApproved = true;

/*
STRUCTURED DATA TYPES
Array: A collection of elements of the same type, accessed by an index.
*/
int numbers[5] = {1,2,3,4,5}; //array in integers
/*
STRUCTURED DATA TYPES
Struct and Class: Allow grouping different types of data under the same name, creating new strucures.
*/
struct person {
    //string name1;
    int age1;
    float height1;
};

/*
VOID
The void type is used to indicate that a function does not return any value.
I is not used to store variable.
*/
void displayMessage() {
    //cout <<"hello, world" <<endl;
};
/*
SIGNED AND UNSIGNED TYPES
*/
signed int signedNumber = -100;   // Can be negative or positive
unsigned int unsignedNumber = 200; // Only positive
/*
INT, SHORT, LONG, LONG LONG
Choosing the appropriate data type helps optimize memory usage and program performance
*/
short int smallNum = 32000;          // For small values
int standardNumber = 100000;         // For common values
long int largeNumber = 1000000000;   // For large values
long long int veryLargeNumber = 1000000000000; // For enormous values