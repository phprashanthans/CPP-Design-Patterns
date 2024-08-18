#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class House {
    public:
        virtual void buildWalls() = 0;
        virtual void buildRoof() = 0;
        virtual void buildDoors() = 0;
        virtual void buildWindows() = 0;
        void buildHouse() {
            buildWalls();
            buildRoof();
            buildDoors();
            buildWindows();
            cout << "House is built" << endl;
        }
};

class LuxuryHouse : public House {
    public:
        void buildWalls() override {
            cout << "Building walls for luxury house\n";
        }
        void buildRoof() override {
            cout << "Building Roof for luxury house\n";
        }
        void buildDoors() override {
            cout << "Building Doors for luxury House\n";
        }
        void buildWindows() override {
            cout << "Building windows for luxury house\n";
        }
};

class StandardHouse : public House {
    public:
        void buildWalls() override {
            cout << "Building walls for Standard house\n";
        }
        void buildRoof() override {
            cout << "Building Roof for Standard house\n";
        }
        void buildDoors() override {
            cout << "Building Doors for Standard House\n";
        }
        void buildWindows() override {
            cout << "Building windows for Standard house\n";
        }
};

int main()
{
    StandardHouse sh;
    sh.buildHouse();
    LuxuryHouse lh;
    lh.buildHouse();
    return 0;
}