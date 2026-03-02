#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void readCharByChar(ifstream& file){
   cout<<"\n_Character_by_character_reading_\n";
   char ch;
   while (file.get(ch)){
      cout<<ch<<endl;
   }
   file.clear();
   file.seekg(0);
}
void readWithCharArray(ifstream& file){
   cout<<"\nReading with character array(getline)\n";
   char buffer[80];
   while (file.getline(buffer, 80)){
      cout<<buffer<<endl;
   }
   file.clear();
   file.seekg(0);
}
void readLineByLine(ifstream& file){
   cout<<"\n_LineByLine_reading(getline with string)_\n";
   string line;
   while (getline(file, line)){
      cout<<line<<endl;
   }
}

int main(){
   ofstream writeFile("example_write.txt", ios::out| ios::trunc);
   writeFile<< "line1: text written with ofstream\n";
   writeFile.close();

   ifstream readFile("example_write.txt", ios::in);
   if (readFile.is_open()) {
      readCharByChar(readFile);
      readWithCharArray(readFile);
      readLineByLine(readFile);
   } else {
      cout<<"error opening the file for reading."<<endl;
   }

   fstream rwFile("example_write.txt", ios::in|ios::out|ios::app);
   if(rwFile.is_open()){
      rwFile<<"New file added using fstream\n";
      rwFile.seekg(0);
      cout<<"\n_Reading with fstream(app mode)\n";

      string line;
      while (getline(rwFile, line)){
         cout<<line<<endl;
      } 
      rwFile.close();
   } else {
      cout<<"error opening file with fstream"<<endl;
   }
   
   ofstream binFile("example_binary.dat",ios::out|ios::binary);
   if(binFile.is_open()){
      string binData = "file saved in binary mode\n";
      binFile.write(binData.c_str(),binData.size());
      binFile.close();
      cout<<"\n_File saved in binary mode_\n";
   }

   fstream ateFile("example_ate", ios::in|ios::out|ios::ate);
   if(ateFile.is_open()){
      ateFile<<"writing at the end using ios::ate\n";
      ateFile.seekg(0);
      cout<<"\nreading adter ios::ate\n";
      
      string line;
      while (getline(ateFile, line)){
         cout<<line<<endl;
      }
      ateFile.close();
   }
   return 0;
}