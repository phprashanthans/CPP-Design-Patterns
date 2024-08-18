#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Collegue {
    public:
        string name;
        virtual void raiseBid(int val) = 0;
        string getName() {
            return name;
        }
        virtual void receiveNotification(int val) = 0;
};

class AuctionMediator {
    public:
        virtual void placeBid(Collegue* cl, int val) = 0;
        virtual void addBidder(Collegue* cl) = 0;
};

class Auction : public AuctionMediator {
    private:
        vector<Collegue*> bidderlist;
    public:
        void addBidder(Collegue* cl){
            bidderlist.push_back(cl);
        }
        void placeBid(Collegue* cl, int val) {
            for(auto &it : bidderlist) {
                if(it->getName() != cl->getName()){
                    it->receiveNotification(val);
                }
            }
        }
};

class Bidder : public Collegue {
    private:
        AuctionMediator* auctionmediator;
    public:
        Bidder(string name, AuctionMediator* am) {
            this->name = name;
            auctionmediator = am;
            auctionmediator->addBidder(this);
        }
        void raiseBid(int val) override {
            auctionmediator->placeBid(this, val);
        }
        void receiveNotification(int val) override {
            std::cout << "Bidder:" << name << " received notification for bid:" << val << std::endl;
        }
        string getName(){
            return name;
        }
};

int main()
{
    AuctionMediator* auct = new Auction();
    Collegue* cl1 = new Bidder("Sanay", auct);
    Collegue* cl2 = new Bidder("Uday", auct);
    cl1->raiseBid(200);
    cl2->raiseBid(250);
    cl1->raiseBid(300);
    return 0;
}
