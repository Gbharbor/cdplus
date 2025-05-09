#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void writeBin(const string& text) {
   ofstream fille("doc.bin, ios::binary");
   if (fille) {
      fille.write(text.c_str(), text.size());
   } else {
      cerr<<"Error trying to open"<<endl;
   }
}
int main() {
   string message = "try one more time";
   cin>>message;
   writeBin(message);
   return 0;
}

