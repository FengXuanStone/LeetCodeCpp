//
// Created by fengxuan on 2016/9/1.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; ++i) {
            if(nums[i] < nums[i - 1]) return i - 1;
        }

        return n - 1;
    }

    int findPeakElement1(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] < nums[mid + 1]) left = mid + 1;
            else right = mid;
        }

        return left;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
