#include <iostream>
using namespace std;

class Product {
   private : 
      double price;
   public: 
      void setPrice(double p) {
         if(price > p) {
            price = p;
         }
      }
      double getPrice() {
         return price;
      }
};
int main () {
   Product cell;
   cell.setPrice(200.00);
   cout<<"product price: "<<cell.getPrice()<<endl;
   return 0;
}