//
// Created by fengxuan on 2016/10/11.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size() - 1;
        int max = 0;

        for(int i = 0; i <= max && max < size; i++) {
            if(i + nums[i] > max) max = i + nums[i];
        }

        return max >= size;
    }
};


int main() {

    vector<int> v1 = {3,2,1,0,4};
    Solution* ss = new Solution;
    cout << ss->canJump(v1) << endl;


    return 0;
}
