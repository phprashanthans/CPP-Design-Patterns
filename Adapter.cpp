/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class WeighingMachine {
    public:
        virtual int measureWeight() = 0;
};

class BabyWeighingMachine : public WeighingMachine{
    public:
        int measureWeight() override {
            return 10;   
        }
};

class AdultWeighingMachine : public WeighingMachine{
    public:
        int measureWeight() override {
            return 100;   
        }
};

class WeightAdapter {
    private:
        WeighingMachine* weighingmachine;
    public:
        WeightAdapter(WeighingMachine* wm){
            weighingmachine = wm;
        }
        int convertToKg(){
            int weightInPounds = weighingmachine->measureWeight();
            return weightInPounds*0.45;
        }
};

class Client {
    private: 
        WeightAdapter* wa;
    public:
        Client(WeightAdapter* wa){
            this->wa = wa;
        }
        int getWeight(){
            return wa->convertToKg();
        }
};

int main() {
    WeighingMachine* bwm = new AdultWeighingMachine();
    WeightAdapter* wa = new WeightAdapter(bwm);
    Client* client = new Client(wa);
    cout << "Weight in kilos:" << client->getWeight() << endl; 
}
