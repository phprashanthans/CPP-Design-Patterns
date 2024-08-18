#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class SingleRoom;
class DoubleRoom;
class DeluxeRoom;

class HotelVisitor {
    public:
        virtual void visit(SingleRoom* r) = 0;
        virtual void visit(DoubleRoom* r) = 0;
        virtual void visit(DeluxeRoom* r) = 0;
};

class HotelRoom {
    public:
        int price;
        virtual void accept(HotelVisitor* hv) = 0;
};

class SingleRoom : public HotelRoom {
    public:
    void accept(HotelVisitor* hv) {
        hv->visit(this);
    }
    const int getPrice() {
        return price;
    }
};

class DoubleRoom : public HotelRoom {
    public:
    void accept(HotelVisitor* hv) {
        hv->visit(this);
    }
    const int getPrice() {
        return price;
    }
};

class DeluxeRoom : public HotelRoom {
    public:
    void accept(HotelVisitor* hv) {
        hv->visit(this);
    }
    const int getPrice() {
        return price;
    }
};

class PriceVisitor : public HotelVisitor {
    public:
        void visit(SingleRoom* r) {
            r->price = 1000;
            std::cout << "Price of single room is: 1000\n";
        }
        void visit(DoubleRoom* r) {
            r->price = 2000;
            std::cout << "Price of double room is: 2000\n";
        }
        void visit(DeluxeRoom* r) {
            r->price = 5000;
            std::cout << "Price of deluxe room is: 1000\n";
        }
};

class MaintenanceVisitor : public HotelVisitor {
    public:
        void visit(SingleRoom* r) {
            std::cout << "Maintenance done for single room\n";
        }
        void visit(DoubleRoom* r) {
            std::cout << "Maintenance done for double room\n";
        }
        void visit(DeluxeRoom* r) {
            std::cout << "Maintenance done for deluxe room\n";
        }
};

int main()
{
    HotelRoom *hr = new SingleRoom();
    HotelVisitor* pv = new PriceVisitor();
    HotelVisitor* mv = new MaintenanceVisitor();
    hr->accept(pv);
    hr->accept(mv);
    return 0;
}
