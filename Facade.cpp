#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Engine{
    public:
        void startEngine(){
            cout << "Started Engine !!\n";
        }
        void stopEngine(){
            cout << "Stopped Engine !!\n";
        }
};
class Lights{
    public:
        void onLights(){
            cout << "Lights turned on !!\n";
        }
        void offLights(){
            cout << "Lights turned off !!\n";
        }
};
class Car{
    private:
        Engine engine;
        Lights lights;
    public:
        void startCar(){
            engine.startEngine();
            lights.onLights();
            cout << "Car ready to drive!\n";
        }
        void stopCar(){
            engine.stopEngine();
            lights.offLights();
            cout << "Car stopped!\n";
        }
};

int main() {
    Car *car = new Car();
    car->startCar();
    car->stopCar();
}