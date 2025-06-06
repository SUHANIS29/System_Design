#include<iostream>
using namespace std;
class cake{
  public:
  virtual void prepare()=0; //abstract method

};
class basic:public cake{
  public:
  void prepare() override {
    cout << "Preparing Basic Cake" << endl;
  }
};
class standard:public cake{
  public:
  void prepare() override {
    cout << "Preparing std Cake" << endl;
  }
};
class premium:public cake{
  public:
  void prepare() override {
    cout << "Preparing premium Cake" << endl;
  }

};
class CakeFactory{
  public:
  virtual cake* createCake(string type)=0;
};
class maidaCake:public CakeFactory{
public:
cake* createCake(string type) {
    if (type == "basic") {
      return new basic();
    } else if (type == "standard") {
      return new standard();
    } else if (type == "premium") {
      return new premium();
    } else {
      return nullptr;
    }
  }
};
class basicsuji:public cake{
  public:
  void prepare() override {
    cout << "Preparing Basic Suji Cake" << endl;
  }
};
class standardsuji:public cake{
  public:
  void prepare() override {
    cout << "Preparing Standard Suji Cake" << endl;
  }
};
class premiumsuji:public cake{
  public:
  void prepare() override {
    cout << "Preparing Premium Suji Cake" << endl;
  }
};

class healthyCake:public CakeFactory{
public:
cake* createCake(string type) {
    if (type == "basic") {
      return new basicsuji();
    } else if (type == "standard") {
      return new standardsuji();
    } else if (type == "premium") {
      return new premiumsuji();
    } else {
      return nullptr;
    }
  }
};
int main(){
  string type="premium";
  CakeFactory *myfactory = new maidaCake();
  cake *Cake = myfactory->createCake(type);
 
    if (Cake) {
        Cake->prepare();
    } else {
        cout << "Invalid cake type!" << endl;
    }

    delete Cake;
    delete myfactory;
  return 0;
}