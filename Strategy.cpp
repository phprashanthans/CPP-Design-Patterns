#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class SortingStrategy {
    public:
        virtual void sort(vector<int>& nums) = 0;
};

class BubbleSort : public SortingStrategy {
    public:
        void sort(vector<int>& nums){
            // Using Bubble sort;
            cout << "Nums sorted using bubble sort\n";
        }
};

class QuickSort : public SortingStrategy {
    public:
        void sort(vector<int>& nums){
            // Using Quick sort;
            cout << "Nums sorted using quick sort\n";
        }
};

class SortContext {
    private:
        SortingStrategy* tech;
    public:
        SortContext(SortingStrategy* tech){
            this->tech = tech;
        }
        void executeSort(vector<int>& nums){
            tech->sort(nums);
        }
};

int main() {
    BubbleSort bs;
    QuickSort qs;
    SortContext ctx(&bs);
    vector<int> nums = {1, 2, 3, 4};
    ctx.executeSort(nums);
    return 0;
}
----------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <memory>

// Define a strategy interface
class Strategy {
    public:
        virtual ~Strategy() = default;
        virtual void execute() const = 0;
};

// Implement the execute method for different scenarios
class OffensiveStrategy : public Strategy {
    public:
        void execute() const override {
            std::cout << "Using offensive strategy! Attack !!!!\n";
        }
};
class DefensiveStrategy : public Strategy {
    public:
        void execute() const override {
            std::cout << "Using defensive strategy! Protective !!!\n";
        }
};
class Player {
    public:
        Player(std::unique_ptr<Strategy> initialStrategy) :
            strategy(std::move(initialStrategy)) {}
        void setStrategy(std::unique_ptr<Strategy> newStrategy) {
            strategy = std::move(newStrategy);
        }
        void play() const {
            strategy->execute();
        }
    private:
        std::unique_ptr<Strategy> strategy;
};

int main() {
    Player player(std::make_unique<OffensiveStrategy>());
    player.play();
    player.setStrategy(std::make_unique<DefensiveStrategy>());
    player.play();
    return 0;
}
/*---------------------------------------------------------------------------------
Using offensive strategy! Attack !!!!
Using defensive strategy! Protective !!!
----------------------------------------------------------------------------------*/
