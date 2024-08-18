#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Shape {
    public:
        virtual void draw() = 0;
};

class Circle : public Shape {
    public:
        void draw(){
            cout << "Drawn a Circle!\n";
        }
};
class Square : public Shape {
    public:
        void draw(){
            cout << "Drawn a Square!\n";
        }
};
class Rectangle : public Shape {
    public:
        void draw(){
            cout << "Drawn a Rectangle!\n";
        }
};
class NULLObject : public Shape {
    public:
        void draw(){
            cout << "Not a shape ! Huh\n";
        }
};

class ShapeFactory {
    public:
    static Shape* getShape(char c){
        switch(c){
            case 'c':
                return new Circle();
            case 's':
                return new Square();
            case 'r':
                return new Rectangle();
            default:
                return new NULLObject();
        }
    }
};

int main() {
    Shape* shape = ShapeFactory::getShape('k');
    if(shape)
        shape->draw();
    else
        cout << "Not supported\n";
}