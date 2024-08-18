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
class Cylinder : public Shape {
    public:
        void draw(){
            cout << "Drawn a Cylinder!\n";
        }
};
class Cone : public Shape {
    public:
        void draw(){
            cout << "Drawn a Cone!\n";
        }
};
class Sphere : public Shape {
    public:
        void draw(){
            cout << "Drawn a Sphere!\n";
        }
};

class ShapeFactory {
    public:
        virtual Shape* getShape(char c) = 0;
};
class ShapeFactory2D : public ShapeFactory {
    public:
    Shape* getShape(char c){
        switch(c){
            case 'c':
                return new Circle();
            case 's':
                return new Square();
            case 'r':
                return new Rectangle();
            default:
                return NULL;
        }
    }
};
class ShapeFactory3D : public ShapeFactory {
    public:
    Shape* getShape(char c){
        switch(c){
            case 'c':
                return new Cylinder();
            case 'o':
                return new Cone();
            case 's':
                return new Sphere();
            default:
                return NULL;
        }
    }
};

class Factory {
    public:
    static ShapeFactory* getFactory(char c){
        switch(c){
            case '2':
                return new ShapeFactory2D();
            case '3':
                return new ShapeFactory3D();
            default:
                return NULL;
        }
    }
};

int main() {
    ShapeFactory* sf = Factory::getFactory('3');
    Shape* shape = sf->getShape('s');
    shape->draw();
}