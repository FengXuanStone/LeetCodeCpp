//
// Created by fengxuan on 2016/8/25.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> candidate(3);

        int sum(0), left, right, target(0), n = nums.size();

        for(int i = 0; i < n - 2; ++i) {
            while(i > 0 && i < n - 2 && nums[i] == candidate[0]) i++;

            target = -nums[i];
            if(target < 0) return result;

            candidate[0] = nums[i];
            left = i + 1;
            right = n - 1;
            while (left < right) {
                candidate[1] = nums[left];
                candidate[2] = nums[right];
                sum = nums[left] + nums[right];

                if(sum == target) {
                    result.push_back(candidate);

                    ++left;
                    --right;
                    while (left < right && nums[left] == candidate[1]) ++left;
                    while (left < right && nums[right] == candidate[2]) --right;
                } else if(sum < target) {
                    ++left;
                    while (left < right && nums[left] == candidate[1]) ++left;
                } else {
                    --right;
                    while (left < right && nums[right] == candidate[2]) --right;
                }
            }
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> vec = {1, -1, -1, 0};
    Solution* ss = new Solution;
    ss->threeSum(vec);

    return 0;
}
