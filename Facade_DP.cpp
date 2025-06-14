#include<iostream>
using namespace std;
class PowerSupply{
  public:
  void power(){
    cout<<"power on"<<endl;
  }
};
class Code{
  public:
  void coding(){
    cout<<"coding done"<<endl;
  }
};
class OperatingSystem{
  public:
  void os(){
    cout<<"os on"<<endl;
  }
};
class ComFcade{
  private:
  PowerSupply ps;
  Code c;
  OperatingSystem o;
  public:
  void startCom(){
ps.power();
c.coding();
o.os();
cout<<"boot done"<<endl;
  }

};
int main(){
ComFcade cf;
cf.startCom();
  return 0;
}
