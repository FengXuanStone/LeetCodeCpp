//
// Created by fengxuan on 2016/8/31.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return;

        int left = 0, right = nums.size() - 1;
        while (nums[left] == 0) left++;
        while (nums[right] == 2) right--;

        while (left < right) {
            bool flag = true;

            for(int i = left; i <= right; ++i) {
                if(nums[i] == 0) {
                    swap(nums[left], nums[i]);
                    left++;
                    flag = false;
                } else if(nums[i] == 2) {
                    swap(nums[i], nums[right]);
                    right--;
                    flag = false;
                }
            }

            if(flag) return;
        }
    }
};

int main() {
    cout << "Hello world" << endl;

   vector<int> nums{2,1};
    Solution* ss = new Solution;
    ss->sortColors(nums);

    return 0;
}
