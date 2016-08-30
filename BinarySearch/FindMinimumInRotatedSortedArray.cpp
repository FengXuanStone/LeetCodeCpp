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
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            if(nums[left] < nums[right]) return nums[left];

            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main() {
    cout << "Hello world" << endl;

    strcmp("a","v");

    return 0;
}
