#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ElectronicDevice {
    private:
        string name;
    public:
        ElectronicDevice(const string& name) : name(name) {}
        void turnOn(){
            cout << "The device " << name << " is turned on !" << endl;
        }
        void turnOff(){
            cout << "The device " << name << " is turned off !" << endl;
        }
};

// Command Interface
class Command {
    public:
        virtual void execute() const = 0;
};

// Concrete Commands
class TurnOnCommand : public Command {
    private:
        ElectronicDevice *edevice;
    public:
        explicit TurnOnCommand(ElectronicDevice *elecDevice) : edevice(elecDevice) {}
        void execute() const override {
            edevice->turnOn();          
        }      
};

class TurnOffCommand : public Command {
    private:
        ElectronicDevice *edevice;
    public:
        explicit TurnOffCommand(ElectronicDevice *elecDevice) : edevice(elecDevice) {}
        void execute() const override {
            edevice->turnOff();          
        }      
};

// Invoker
class RemoteControl {
    private:
        vector<Command*> commands;
    public:
        void addCommand(Command* cmd){
            commands.push_back(cmd);
        }
        void pressButton(int slot) {
            if(slot >=0 && slot < commands.size());
                commands[slot]->execute();
        }
};

int main() {
    ElectronicDevice* ac = new ElectronicDevice("AC");
    ElectronicDevice* tv = new ElectronicDevice("TV");
    RemoteControl* remote = new RemoteControl();
    TurnOnCommand t_on(ac);
    TurnOffCommand t_off(ac);
    remote->addCommand(&t_on);
    remote->addCommand(&t_off);
    remote->pressButton(1);
    remote->pressButton(0);
    return 0;
}