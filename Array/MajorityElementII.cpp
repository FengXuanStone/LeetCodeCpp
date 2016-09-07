//
// Created by fengxuan on 2016/9/6.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;

        int m  = 0, n = 0, countM = 0, countN = 0;
        int size = nums.size();

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == m) countM++;
            else if(nums[i] == n) countN++;
            else if(countM == 0) m = nums[i], countM++;
            else if(countN == 0) n = nums[i], countN++;
            else countM--, countN--;
        }

        countM = 0, countN = 0;

        for(auto s : nums) {
            if(s == m) countM++;
            else if(s == n) countN++;
        }

        if(countM > (size / 3)) result.push_back(m);
        if(countN > (size / 3)) result.push_back(n);

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> vec{1,2,3};
    Solution* ss = new Solution;
    ss->majorityElement(vec);

    return 0;
}
