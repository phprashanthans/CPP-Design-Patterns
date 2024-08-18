#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class IceCream {
    private:
    public:
        virtual void Flavor() = 0;
        virtual int cost() = 0;
};

class VanillaIceCream : public IceCream {
    public:
        void Flavor() {
            cout << "Vanilla Flavor IceCream\n";
        }
        int cost(){
            return 100;
        }
};

class StrawberryIceCream : public IceCream {
    public:
        void Flavor() {
            cout << "Strawberry Flavor IceCream\n";
        }
        int cost(){
            return 200;
        }
};

class IceCreamDecorator : public IceCream {
    protected: 
        IceCream* icecream;
    public:
        IceCreamDecorator(IceCream* ic){
            icecream = ic;
        }
        void Flavor(){ icecream->Flavor();}
        int cost(){ return icecream->cost();}
};

class ChocolateDecorator : public IceCreamDecorator {
    public:
        ChocolateDecorator(IceCream* ic) : IceCreamDecorator(ic) {
        }
        void Flavor(){
            icecream->Flavor();
            cout << "Chocolate added\n";
        }
        int cost(){
            return icecream->cost()+20;
        }
};

class CaramelDecorator : public IceCreamDecorator {
    public:
        CaramelDecorator(IceCream* ic) : IceCreamDecorator(ic){
        }
        void Flavor(){
            icecream->Flavor();
            cout << "Caramel added\n";
        }
        int cost(){
            return icecream->cost()+50;
        }
};

int main() {
    VanillaIceCream *vic = new VanillaIceCream();
    vic->Flavor();
    cout << vic->cost();
    
    IceCream *ic = new CaramelDecorator(vic);
    ic->Flavor();
    cout << ic->cost();
    
}