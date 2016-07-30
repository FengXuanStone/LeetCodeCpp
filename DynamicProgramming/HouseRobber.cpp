//
// Created by fengxuan on 2016/7/30.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        int maxValue[nums.size() + 1];

        maxValue[0] =  0;
        maxValue[1] = nums[0];

        for(int i = 2; i < nums.size() + 1; ++i) {
            maxValue[i] = max((maxValue[i - 2] + nums[i - 1]), maxValue[i - 1]);
        }

        return maxValue[nums.size()];
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
