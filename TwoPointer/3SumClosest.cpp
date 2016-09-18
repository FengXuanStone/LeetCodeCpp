//
// Created by fengxuan on 2016/9/12.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int result = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int k = 0; k < n; ++k) {
            int left = 0, right = n - 1;

            while(left < right) {
                if(left == k) ++left;
                else if(right == k) --right;
                else {
                    int tmp = nums[k] + nums[left] + nums[right];
                    int tmpDiff = abs(tmp - target);
                    //update
                    if(tmpDiff < diff) {
                        diff = tmpDiff;
                        result = tmp;
                    }

                    if(tmp < target) ++left;
                    else --right;
                }
            }
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;
    vector<int> vec{0,2,1,-3};
    Solution* ss = new Solution;
    cout << ss->threeSumClosest(vec, 0) << endl;

    return 0;
}
