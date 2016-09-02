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
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;

        int n = nums.size();
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }

        int sec = left;
        left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int readMid = (mid + sec) % n;
            if(nums[readMid] == target) return readMid;
            else if(nums[readMid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};

int main() {
    cout << "Hello world" << endl;
    vector<int> vec{5,1,3};
    Solution* ss = new Solution;
    cout << ss->search(vec, 5) << endl;

    return 0;
}
