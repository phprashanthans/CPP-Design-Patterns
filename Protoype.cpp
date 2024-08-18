#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Shape {
    public:
        virtual void draw() = 0;
        virtual Shape* clone() = 0;
        virtual ~Shape() {}
};

class Circle : public Shape {
    private:
        double radius;
        
    public:
        //Circle(const Circle& circ){ cout << "Copy ctor called\n"; }
        Circle(double radius) : radius(radius) {}
        void draw(){
            cout << "Drawn a circle with radius:" << radius << "\n";
        }
        Shape* clone() {
            return new Circle(*this);
        }
};

class Square : public Shape {
    private:
        double side;
    public:
        Square(double side) : side(side) {}
        void draw(){
            cout << "Drawn a square with side:" << side << "\n";
        }
        Shape* clone() {
            return new Square(*this);
        }
};

int main()
{
    Circle circPrototype(2.5);
    Square sqPrototype(5.7);
    Shape* s1 = circPrototype.clone();
    Shape* s2 = sqPrototype.clone();
    s1->draw();
    s2->draw();
}
