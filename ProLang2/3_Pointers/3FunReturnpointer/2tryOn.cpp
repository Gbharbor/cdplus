#include <iostream>
using namespace std;

int greeting() {
   cout<<"hello, this functions was called through a pointer"<<endl;
   return 0;
}
int farewell() {
   cout<<"goodbye, i was also called via a pointer"<<endl;
   return 1;
}

int main() {
   int(*functionPointer)();
   functionPointer = greeting;
   functionPointer();

   functionPointer = farewell;
   functionPointer();
   return 0;
}