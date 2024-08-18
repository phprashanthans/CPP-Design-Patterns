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