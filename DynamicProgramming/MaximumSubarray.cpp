//
// Created by fengxuan on 2016/8/30.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int max = nums[0];
        int cur = nums[0];

        for(auto i = nums.begin() + 1; i != nums.end(); ++i) {
            int tmp = (*i) + cur;
            cur = tmp > (*i) ? tmp : (*i);

            max = max > cur ? max : cur;
        }

        return max;
    }
};

int main() {
    cout << "Hello world" << endl;

   vector<int> vv{-2,1,-3,4,-1,2,1,-5,4};

    Solution* ss = new Solution;

    ss->maxSubArray(vv);

    return 0;
}
