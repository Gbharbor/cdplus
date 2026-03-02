#include <iostream> 
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main() {
   //string lib
   string name;
   cout<<"Type ur name";
   cin>> name;
   cout<<"hello"<<name<<", ur name has"<<name.length()<<"letters.\n";

   //vector lib & algorithm lib (sort)
   vector <char> letters(name.begin(), name.end());
   sort(letters.begin(),letters.end()); 
   cout<<"Letters of ur name in alphabetical order:";
   for (char letter: letters) {
      cout<<letter<<' ';
   } cout<<endl;
   
   //cmath lib
   cout<<"square root of 225 is: "<<sqrt(225.0) <<endl;
   float base = 13, multiplier = 3, factor =4;
   float result = sqrt(base + multiplier * factor);
   cout<<"square root of(base + multiplier * factor)is: "<<result<<endl;

   return 0;
}