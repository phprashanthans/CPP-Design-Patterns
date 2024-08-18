#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Observer {
    public:
        virtual void notify() = 0;
};

class MobileObserver : public Observer {
    public:
        void notify() override {
            cout << "Mobile User Notified\n";
        }
};

class TVObserver : public Observer {
    public:
        void notify() override {
            cout << "TV User Notified\n";
        }
};

class WeatherStation {
    private:
        double temp;
        list<Observer*> list_obs;
    public:
        void registerObserver(Observer* o){
            list_obs.push_back(o);
        }
        void deregister(Observer* o){
            list_obs.remove(o);
        }
        void notify(){
            for(auto &it : list_obs){
                it->notify();
            }
        }
        void setTemp(double t){
            temp = t;
            cout << "Temp is:" << temp << endl;
            notify();
        }
        double getTemp() {
            return temp;
        }
        
};

int main() {
    MobileObserver mo1;
    TVObserver to1;
    WeatherStation* ws = new WeatherStation();
    ws->registerObserver(&mo1);
    ws->registerObserver(&to1);
    ws->setTemp(45.44);
    MobileObserver mo2;
    ws->registerObserver(&mo2);
    ws->deregister(&to1);
    ws->setTemp(34.7);
}