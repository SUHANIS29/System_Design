#include <iostream>
using namespace std;
// Simple Factory Pattern
class cake
{
public:
  virtual void prepare() = 0;
};
class basic : public cake
{
public:
  void prepare() override
  {
    cout << "Preparing Basic Cake" << endl;
  }
};
class standard : public cake
{
public:
  void prepare() override
  {
    cout << "Preparing Standard Cake" << endl;
  }
};
class premium : public cake
{
public:
  void prepare() override
  {
    cout << "Preparing Premium Cake" << endl;
  }
};
class cakeFactory
{
public:
  cake *createCake(string type)
  {
    if (type == "basic")
    {
      return new basic();
    }
    else if (type == "standard")
    {
      return new standard();
    }
    else if (type == "premium")
    {
      return new premium();
    }
    else
    {
      return nullptr;
    }
  }
};
int main()
{
  string type = "premium";
  cakeFactory myfactory;
  cake *Cake = myfactory.createCake(type);
  Cake->prepare();
  return 0;
}