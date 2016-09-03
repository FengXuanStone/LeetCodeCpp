//
// Created by fengxuan on 2016/9/3.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1)
            return nums[0];

        int n = nums.size();
        vector<int> candidate(n, 0);
        candidate[0] = nums[0];
        for(int i = 1; i < n - 1; ++i) {
            candidate[i] = max(candidate[i - 1], (i == 1 ? 0 : candidate[i - 2]) + nums[i]);
        }
        int result = candidate[n - 2];

        candidate[1] = nums[1];
        for(int i = 2; i < n; ++i) {
            candidate[i] = max(candidate[i - 1], (i == 2 ? 0 : candidate[i - 2]) + nums[i]);
        }

        return max(result, candidate[n - 1]);
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
