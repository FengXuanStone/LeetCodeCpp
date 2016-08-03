//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> count;

public:
    NumArray(vector<int> &nums) {
        if(nums.size() == 0)
            return;

        count.push_back(nums[0]);

        for(int i = 1; i < nums.size(); ++i) {
            count.push_back(count[i - 1] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if(i < 0 || j < 0 || i > j || j > count.size() - 1) return 0;
        else if(i == 0)return count[j];
        else return count[j] - count[i - 1];
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> vec = vector<int>{-2,0,3,-5,2,-1};

    NumArray* aa = new NumArray(vec);

    aa->sumRange(0,2);

    return 0;
}
