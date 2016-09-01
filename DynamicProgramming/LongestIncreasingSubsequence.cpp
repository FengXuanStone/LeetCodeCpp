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
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 0) return 0;

        int size = nums.size();
        vector<int> numsLIS(size, 1);
        vector<int> result;
        vector<int> pre(size, 0);
        int lastNum = 0;
        int max = 1;

        for(int i = 1; i < size; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j] && numsLIS[j] + 1 > numsLIS[i]) {
                    numsLIS[i] = numsLIS[j] + 1;
                    pre[i] = j;
                }

                if(max < numsLIS[i]) {
                    max = numsLIS[i];
                    lastNum = i;
                }
            }
        }

        return max;
    }

    int lengthOfLIS1(vector<int>& nums) {
        if(nums.size() <= 0) return 0;

        int size = nums.size();
        vector<int> numsLIS;
        numsLIS.push_back(nums[0]);

        for(int i = 1; i < size; ++i) {
            int val = nums[i];

            if(val > numsLIS[numsLIS.size() - 1]) {
                numsLIS.push_back(val);
            } else {
                auto k = lower_bound(numsLIS.begin(), numsLIS.end(), val);
                (*k) = val;
            }
        }

        return numsLIS.size();
    }
};

int main() {
    cout << "Hello world" << endl;

    strcmp("a","v");

    return 0;
}
