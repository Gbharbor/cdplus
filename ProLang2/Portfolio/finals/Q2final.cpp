#include<iostream>
using namespace std;
struct hourR {
   int hour;
   int min;
   int sec;
};
int main(){
   hourR now;
   now.hour = 17;
   now.min = 26;
   now.sec = 30;
   cout<<"right now its,"<<now.hour<<":"<<now.min<<":"<<now.sec<<endl;
   return 0;
}