//
// Created by fengxuan on 2016/8/29.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int mid = left + (right - left) / 2;

        while (left < right) {
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
            mid = left + (right - left) / 2;
        }

        return left;
    }
};

int main() {
    cout << "Hello world" << endl;



    return 0;
}
