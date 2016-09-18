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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if(nums.empty())
            return  result;

        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] < target) {
                left = mid + 1;
            } else right = mid;
        }
        if(nums[left] == target) result[0] = left;
        else
            return result;

        left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] <= target) {
                left = mid + 1;
            } else right = mid;
        }
        result[1] = right - 1;

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> vec{1};
    Solution* ss = new Solution;
    vector<int> result = ss->searchRange(vec, 0);

    cout << result[0] << result[1] << endl;

    return 0;
}
