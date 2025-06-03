#include <iostream>
#include <vector>
using namespace std;
class products{
public:
string name;
double rate;
products(string name,double rate){
  this->name=name;
  this->rate=rate;
}};
class shop_cart{
private:
  vector<products*> prod;
  void calculte_price(){

  }
};
class getinvoiceprint{
  private:
  shop_cart* cart;
public:
  getinvoiceprint(shop_cart* cart){
    this->cart=cart;
  }
  void print_invoice(){
    // logic to print invoice
    cout << "Invoice printed." << endl;
  }
};
int main(){
  shop_cart* cart = new shop_cart();
  getinvoiceprint* invoice = new getinvoiceprint(cart);
  
  invoice->print_invoice();
  return 0;
}