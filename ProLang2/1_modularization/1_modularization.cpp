#include <iostream>   // For input and output (cout, cin)
#include <string>     // For string manipulation
#include <algorithm>  // For sort()
#include <vector>     // For vector of characters
#include <cmath>      // For math functions like sqrt()

using namespace std; // All components declared inside the std namespace will be available in our code

int main () {
   // Using string & algorithm
   string name;
   cout << "Type your name: ";
   cin >> name;

   cout << "Hello, " << name << "! Your name has " << name.length() << " letters.\n";

   vector<char> letters(name.begin(), name.end());
   sort(letters.begin(), letters.end());

   cout << "Letters of your name in alphabetical order: ";
   for (char letter : letters) {
      cout << letter << ' ';
   }
   cout << endl;

   // Using math functions
   cout << "Square root of 225 is: " << sqrt(225.0) << endl;

   // Math functions with variables
   float base = 13, multiplier = 3, factor = 4;
   float result = sqrt(base + multiplier * factor);
   cout << "Square root of (base + multiplier * factor) is: " << result << endl;

   return 0;
}