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
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty() || k > nums.size()) return 0;

        multiset<int> candidate;
        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            if(candidate.size() < k) {
                candidate.insert(nums[i]);
            } else {
                auto k = candidate.begin();
                if((*k) < nums[i]) {
                    candidate.erase(k);
                    candidate.insert(nums[i]);
                }
            }
        }

        return *candidate.begin();
    }

    int findKthLargest1(vector<int>& nums, int k) {
        int L = 0, R = nums.size() - 1;

        while (L < R) {
            int left = L, right = R;
            int tmp = nums[left];
            while (left < right) {
                while (left < right && nums[right] < tmp) --right;
                nums[left] = nums[right];
                while (left < right && nums[left] >= tmp) ++left;
                nums[right] = nums[left];
            }
            nums[left] = tmp;
            if(left == k - 1) return nums[k - 1];
            else if(left > k - 1) R = left - 1;
            else L = left + 1;
        }

        return nums[k - 1];
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> num{-1, 2, 0};
    Solution* ss = new Solution;
    cout << ss->findKthLargest1(num, 1) << endl;

    return 0;
}
