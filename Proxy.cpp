#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Image {
    public:
    virtual void display() = 0;  
};

class RealImage : public Image {
    private:
        string filename;
    public:
        RealImage(const string& filename) : filename(filename) {
            cout << "Loading image file: "<< filename << endl;
        }
        void display() override {
            cout << "Displaying Image: " << filename << endl;
        }
};

class ImageProxy : public Image {
    private:
        RealImage *realimage;
        string filename;
    public:
        ImageProxy(const string& filename) : filename(filename){
            realimage = NULL;
        }
        void display() override {
            if(realimage == NULL)
                realimage = new RealImage(filename);
            realimage->display();
        }
};

int main() {
    ImageProxy *imageproxy = new ImageProxy("abc.png");
    imageproxy->display();
    imageproxy->display();
    delete imageproxy;
}