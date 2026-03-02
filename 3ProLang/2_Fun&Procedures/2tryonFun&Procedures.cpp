#include <iostream>
#include <string>
using namespace std;
//Try menu 
void writeMenu() {
   cout<<"\n1- Register";
   cout<<"\n2- List";
}

//try function with return result
int calculateFactorial(int x) {
   int result = 1;
   while (x != 1) {
      result *= x;
      x--;
   }
   return result;
}

//return types (struct)
struct Point { 
   int x, y;
};
Point createPoint(int x, int y) {
   Point p = {x,y};
   return p;
};

//return types (class)
class Person {
   public: 
      string name;
      int age;
      Person(string name, int age) : name(name), age(age) {}
};
Person createPerson(string name, int age) {
   return Person(name, age);
}

//return types (int)
int sum(int a, int b) {
   return a + b;
}

//return types (float)
float avarage (float a, float b) {
   return(a + b) / 2;
}

//return types (bool)
bool isEven (int num) {
   return num % 2 == 0;
}

//return types (char)
char firstCharacter(string str) {
   return str[0];
}

//return types (pointer int*)
int* findMaxNum(int arr[], int size) {
   int* max = &arr[0];
   for (int i = 1; 1 < size; i++) {
      if(arr[i] > *max) {
         max = &arr[i];
      }
   }
   return max;
}

//return type (reference int&)
int& greaterNumber(int& a, int& b) {
   if(a > b) {
      return a;
   }
   return b;
}

//return type (string)
std::string greeting() {
   return "hello world, welcome to C++";
}
//Call Functions
void function0() {
   cout<<"Function 0"<<endl;
}
void function1() {
   cout<<"Function 1"<<endl;
}
void function2() {
   cout<<"i am Function 2, i will call function 0 & 1"<<endl;
   function0();
   function1();
}

//global functions
void globalFunction0();
void globalFunction1();
void globalFunction2();
int globalVar = 100;
void globalFunction3() {
   cout<<"Im function 3"<<endl;
   cout<<"Global Var inside the function 3: "<<globalVar<<endl;
}
void globalFunction4();
void globalFunction2() {   
   cout<<"im global function 2, i will call too global function 0 & 1"<<endl;
   void globalFunction0();
   void globalFunction1();
}
void globalFunction0() {cout<<"i am global function 0"<<endl;}
void globalfunction1() {cout<<"i am global function 1"<<endl;}
void globalFunction4() {cout<<"i am global function 4"<<endl;}

//Function Parameter by value (do not change the original)
void doubleValue(int number) {
   number = number * 2;
   cout<<"inside the function(by value): "<<number<<endl;
}

//Function Parameter by reference-pointer (change the original)
void doubleValueByReference(int* number) {
   *number = (*number) * 2;
   cout<<"inside the function by reference: "<<*number<<endl;
}

int main() {
   //Try menu 
   writeMenu();
   //try function with return result
   int factorial = calculateFactorial(5);
   cout<<"Factorial 5 is : "<<factorial<<endl;
   //return types (struct)
   Point p = createPoint(3, 4);
   cout<<"Point created: "<<p.x<<" & "<<p.y<<endl;
   //return types (class)
   Person person = createPerson ("Gui", 27);
   cout<<"Person created: "<<person.name<<"Age"<<person.age<<endl;
   //return types (int)
   cout<<"Sum: "<<sum(10,5)<<endl;
   //return types (float)
   cout<<"Avarage: "<<avarage(5.0, 7.0)<<endl;
   //return types (bool)
   cout<<"6 isEven ? "<<(isEven(6) ? "yes" : "no")<<endl;
   //return types (char)
   cout<<"First Charactere: "<<firstCharacter("hello")<<endl;
   //return types (pointer *int)
   int arr[] = {1, 2, 3, 9, 5};
   int* maximum = findMaxNum(arr, 5);
   cout<<"bigger number in array: "<<*maximum<<endl;
   //return type (reference int&)
   int a = 10, b = 20;
   int& bigger = greaterNumber(a, b);
   cout<<"bigger number about a & b: "<<bigger<<endl;
   //return type (string)
   cout<<greeting()<<endl;
   //call functions:
   function0();
   function1();
   function2();
   //Global Functions
   globalFunction0();
   globalFunction1();
   globalFunction2();
   //global var
   globalFunction3();
   //Global Function specific
   globalFunction4();
   //Function Parameter by value
   cout<<"trying parameter by value: "<<endl;
   int value0 = 10;
   cout<<"before the function (by value): "<<value0<<endl;
   doubleValue(value0);
   cout<<"After the function (by value): "<<value0<<endl;
   //Function Parameter by reference-pointer
   int value1 = 10;
   cout<<"before the function (by reference): "<<value1<<endl;
   doubleValueByReference(&value1);
   cout<<"after the function (by reference): "<<value1<<endl;

   return;
}