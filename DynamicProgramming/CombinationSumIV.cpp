//
// Created by fengxuan on 2016/8/7.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;

        sort(nums.begin(), nums.end());

        for(int i = 1; i <= target; ++i) {
            for(auto j = nums.cbegin(); j != nums.cend(); ++j) {
                if(i < (*j)) break;
                dp[i] += dp[i - (*j)];
            }
        }

        return dp.back();
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
