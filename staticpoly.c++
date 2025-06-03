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
//overloading the accelerate method
void accelerte(){
    if (!isengineon) {
        cout << "Start the engine first!" << endl;
        return;
    }
    curr_speed += 10; // increase speed by 10
    cout << "Accelerating. Current speed: " << curr_speed << " km/h" << endl;
  } 
void accelerate(int speed){
    if (!isengineon) {
        cout << "Start the engine first!" << endl;
        return;
    }
    curr_speed += speed; // increase speed by given amount
    cout << "Accelerating. Current speed: " << curr_speed << " km/h" << endl;
}

  virtual void brake()=0 //abstract method for dynamic polymorphism
  // virtual ~Car() // virtual destructor for base class
  // {
  //   cout << "Car destroyed" << endl;
  // }
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
  mancar->accelerate(20); //accelerate by 20 km/h
  return 0;
}