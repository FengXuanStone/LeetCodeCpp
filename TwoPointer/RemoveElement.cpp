//
// Created by fengxuan on 2016/7/30.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;

        int i = 0, j = nums.size() - 1;

       while (i <= j) {
           if(nums[i] == val) {
               int tmp = nums[i];
               nums[i] = nums[j];
               nums[j] = tmp;
               --j;
           } else {
               ++i;
           }
       }

        return j + 1;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> vec = {4,5};

    Solution* ss = new Solution;
    cout << ss->removeElement(vec, 5) << endl;

    return 0;
}
