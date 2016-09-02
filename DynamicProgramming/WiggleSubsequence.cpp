//
// Created by fengxuan on 2016/9/2.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;

        int i = 1;
        while (i < n && nums[i] == nums[i - 1]) ++i;
        if(i == n) return 1;

        int result = 2;
        int mNum = nums[i];
        bool up = nums[i] > nums[i - 1];

        for(; i < n - 1; ++i) {
            if(up) {
                if(nums[i + 1] >= mNum) {
                    mNum = max(mNum, nums[i + 1]);
                } else {
                    result++;
                    up = !up;
                    mNum = nums[i + 1];
                }
            } else {
                if(nums[i + 1] <= mNum) {
                    mNum = min(mNum, nums[i + 1]);
                } else {
                    result++;
                    up = !up;
                    mNum = nums[i + 1];
                }
            }
        }
        return result;
    }
};

int main() {
    cout << "Hello world" << endl;
    vector<int> vec{1,17,5,10,13,15,10,5,16,8};

    Solution* ss = new Solution;
    cout << ss->wiggleMaxLength(vec) << endl;

    return 0;
}
