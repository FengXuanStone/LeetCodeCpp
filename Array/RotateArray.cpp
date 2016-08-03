//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size() - 1;

        for(int i = 0; i < k; ++i) {
            int tmp = nums[size];
            for(int j = size; j > 0; --j) {
                nums[j] = nums[j - 1];
            }
            nums[0] = tmp;
        }
    }

    void rotate1(vector<int>& nums, int k) {
        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    void rotate2(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k == 0)
            return;

        vector<int> tmp;

        tmp.insert(tmp.end(), nums.begin() + nums.size() - k, nums.end());
        tmp.insert(tmp.end(), nums.begin(), nums.begin() + nums.size() - k);

        nums = tmp;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
