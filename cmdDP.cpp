#include <iostream>
using namespace std;

// Abstract Command
class ICommand
{
public:
  virtual void execute() = 0;
  virtual void undo() = 0;
  virtual ~ICommand() {}
};

// Receiver - Light
class Light
{
public:
  void turnOn()
  {
    cout << "Light is ON" << endl;
  }

  void turnOff()
  {
    cout << "Light is OFF" << endl;
  }
};

// Concrete Command for Light
class light_cmd : public ICommand
{
private:
  Light *light;

public:
  light_cmd(Light *l) : light(l) {}

  void execute() override
  {
    light->turnOn();
  }

  void undo() override
  {
    light->turnOff();
  }
};

// Receiver - Fan
class Fan
{
public:
  void turnOn()
  {
    cout << "Fan is ON" << endl;
  }

  void turnOff()
  {
    cout << "Fan is OFF" << endl;
  }
};

// Concrete Command for Fan
class FanCommand : public ICommand
{
private:
  Fan *fan;

public:
  FanCommand(Fan *f) : fan(f) {}

  void execute() override
  {
    fan->turnOn();
  }

  void undo() override
  {
    fan->turnOff();
  }
};

// Invoker - Remote
class Remote
{
private:
  static const int num_buttons = 4;
  ICommand *commands[num_buttons];
  bool isOn[num_buttons];

public:
  Remote()
  {
    for (int i = 0; i < num_buttons; ++i)
    {
      commands[i] = nullptr;
      isOn[i] = false;
    }
  }

  void setCommand(int button, ICommand *command)
  {
    if (button >= 0 && button < num_buttons)
    {
      commands[button] = command;
    }
  }

  void pressButton(int button)
  {
    if (button >= 0 && button < num_buttons && commands[button])
    {
      if (!isOn[button])
      {
        commands[button]->execute();
        isOn[button] = true;
      }
      else
      {
        commands[button]->undo();
        isOn[button] = false;
      }
    }
    else
    {
      cout << "No command set for button " << button << endl;
    }
  }
};

int main()
{
  Light *livingRoomLight = new Light();
  Fan *ceilingFan = new Fan();

  ICommand *lightCommand = new light_cmd(livingRoomLight);
  ICommand *fanCommand = new FanCommand(ceilingFan);

  Remote *remote = new Remote();

  remote->setCommand(0, lightCommand);
  remote->setCommand(1, fanCommand);

  cout << "For button 0 (Light):" << endl;
  remote->pressButton(0); // ON
  remote->pressButton(0); // OFF

  cout << "\nFor button 1 (Fan):" << endl;
  remote->pressButton(1); // ON
  remote->pressButton(1); // OFF

  cout << "\nFor buttons 2 and 3 (Unset):" << endl;
  remote->pressButton(2); // No command
  remote->pressButton(3); // No command

  // Clean up
  delete lightCommand;
  delete fanCommand;
  delete livingRoomLight;
  delete ceilingFan;
  delete remote;

  return 0;
}
