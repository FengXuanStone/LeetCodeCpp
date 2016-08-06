//
// Created by fengxuan on 2016/8/6.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            res ^= i ^ nums[i];
        }

        res ^= nums.size();

        return res;
    }

    int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;

        for(auto i = nums.cbegin(); i != nums.cend(); ++i) {
            sum -= (*i);
        }

        return sum;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
