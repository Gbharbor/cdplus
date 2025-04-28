#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    // ---------------- Input Data ----------------
    // Ask the user to input their name.
    string name;
    cout << "Type your name: ";
    cin >> name;

    // Greet the user and display the number of letters in their name.
    cout << "Hello " << name << ", your name has " << name.length() << " letters.\n";

    // ---------------- Convert String to Character Vector ----------------
    /*
    This block copies each letter from the string 'name' into a character vector called 'letters'.
    - 'name.begin()' is the start of the string and 'name.end()' is the end of it.
    - 'vector<char>' is used to store the characters from the string.
    */
    vector<char> letters(name.begin(), name.end());

    // ---------------- Sorting the Character Vector ----------------
    /*
    Here, we are sorting the 'letters' vector in alphabetical order (based on the ASCII value of each character).
    The 'sort' function organizes the elements of the vector from beginning to end.
    */
    sort(letters.begin(), letters.end());
    cout << "Letters of your name in alphabetical order: ";

    // ---------------- Displaying the Sorted Letters ----------------
    /*
    This loop goes through the 'letters' vector, printing each character one by one.
    The character is stored in the 'letter' variable during each iteration.
    */
    for (char letter : letters) {
        cout << letter << ' ';
    }
    cout << endl;//just breke line

    // ---------------- Mathematical Function ----------------
    /*
    Calculating the square root of 225 using the 'sqrt' function from the 'cmath' library.
    The 'sqrt' function returns the square root of a number.
    */
    cout << "Square root of 225 is: " << sqrt(225.0) << endl;

    // ---------------- Mathematical Function with Variables ----------------
    /*
    Using variables to calculate the square root of a mathematical expression.
    The expression 'base + multiplier * factor' will be calculated before applying the square root.
    */
    float base = 13, multiplier = 3, factor = 4;
    float result = sqrt(base + multiplier * factor);
    cout << "Square root of (base + multiplier * factor) is: " << result << endl;

    return 0;
}