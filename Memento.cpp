#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Memento {
    private:
        int height;
        int width;
    public:
        Memento(int h, int w) : height(h), width(w) {}
        int getHeight() {return height;}
        int getWidth() {return width;}
};

class ConfigOriginator {
    private:
        int height;
        int width;
    public:
        ConfigOriginator(int h, int w) : height(h), width(w) {}
        Memento createMemento(){
            return Memento(height, width);
        }
        void restoreMemento(Memento memento) {
            this->height = memento.getHeight();
            this->width = memento.getWidth();
        }
        void printConfig(){
            cout << "Height:" << height << ", Width:" << width << endl;
        }
        void setHeight(int h) {
            height = h;
        }
        void setWidth(int w) {
            width = w;
        }
};

class Caretaker {
    private:
        vector<Memento> memento_list;
    public:
        void addMemento(Memento memento) {
            memento_list.push_back(memento);
        }
        Memento GetMemento(int idx){
            if(idx >= 0 && idx < memento_list.size()) {
                return memento_list[idx];
            }
            //return std::out_of_range("Invalid Index");
        }
};

int main()
{
    ConfigOriginator* co1 = new ConfigOriginator(10, 15);
    co1->printConfig();
    Memento m = co1->createMemento();
    Caretaker* ct = new Caretaker();
    ct->addMemento(m);
    co1->setHeight(20); co1->setWidth(30);
    co1->printConfig();
    co1->restoreMemento(ct->GetMemento(0));
    co1->printConfig();
    return 0;
}
