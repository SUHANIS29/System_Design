#include <iostream>
using namespace std;
class car{
  protected:
  string brand;
  string model;
  int curr_speed;
  bool isengineon;
public:
//common characteristics and behaviour for all cars
car(string b,string m)
{
  this->brand=b;
  this->model=m;
  this->curr_speed=0;
}
void startengine(){ //abstraction
  isengineon=true;
  cout<<"engine started"<<endl;
}
void stopengine(){ //abstraction no need to know how it is implemented
  //just know that it stops the engine
  isengineon=false;
  cout<<"engine stopped"<<endl;
}
  virtual void accelerte()=0 //abstract method for dynamic polymorphism

  virtual void brake()=0 //abstract method for dynamic polymorphism
  // virtual ~Car() // virtual destructor for base class
  // {
  //   cout << "Car destroyed" << endl;
  // }
};
class electricCar:public car{ //inherint from car
private:
  int batt_status;
  public:
  electricCar(string b,string m):car(b,m){
    batt_status=100; //battery status in percentage
  }
  void chargebatt(){
    batt_status=100; //charge battery to 100%
    cout<<"battery charged fuully "<<batt_status<<endl;
  }
void accelerate() {
    if (!isengineon) {
        cout << "Start the engine first!" << endl;
        return;
    }
    if (batt_status <= 0) {
        cout << "Battery is dead. Please charge the battery." << endl;
        return;
    }
    batt_status -= 10; // decrease battery status by 10%
  }
};



class manualCar :public car{ //inherint from car
  private:
  int curr_gear;//only for manual cars
  // access all features of car like
  // protected:
  // string brand;
  // string model;
  // int curr_speed;
  // bool isengineon;
public:
manualCar(string b,string m):car(b,m) //call parent constructor
{
  curr_gear=0;
}
//only for manual cars
void shiftgear(int gear){
curr_gear=gear;
  cout<<"gear shifted to "<<curr_gear<<endl;
}
//override
void accelerate()
{
if (!isengineon) {
    cout << "Start the engine first!" << endl;
    return;
  }
  curr_speed += 10; // increase speed by 10
  cout << "Accelerating. Current speed: " << curr_speed << " km/h" << endl;
}
};
int main(){
  manualCar* mancar=new manualCar("Toyota","Corolla");
  mancar->startengine();
  mancar->shiftgear(2); //only for manual cars
  mancar->stopengine();

  mancar->accelerate(); //only for manual cars
  electricCar* elecar=new electricCar("Tesla","Model S");
  elecar->startengine();
  elecar->chargebatt(); //only for electric cars
  elecar->stopengine();
  elecar->accelerate(); //only for electric cars
  return 0;
}