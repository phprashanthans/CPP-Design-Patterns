#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Color {
    public:
    virtual void setColor() = 0;    
};
class Shape{
    public:
        virtual void drawAndColor() = 0;
};

class Green : public Color{
    public:
        void setColor(){
            cout << "Filling with Green Color\n";
        }
};
class Red : public Color{
    public:
        void setColor(){
            cout << "Filling with Red Color\n";
        }
};

class Circle : public Shape {
    private:
        Color& color;
    public:
        Circle(Color& color) : color(color) {
        }
        void drawAndColor(){
            cout << "Drawn a circle\n";
            color.setColor();
        }
};
class Square : public Shape {
    private:
        Color& color;
    public:
        Square(Color& color) : color(color){
        }
        void drawAndColor(){
            cout << "Drawn a square\n";
            color.setColor();
        }
};

int main() {
    Green green;
    Red red;
    
    Circle circle(green);
    Square square(red);
    
    circle.drawAndColor();
    square.drawAndColor();
}