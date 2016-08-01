//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> candidate;

        for(int i = 0; i < nums.size(); ++i) {
            if(candidate.find(nums[i]) != candidate.end() && i - candidate[nums[i]] <= k)
                return true;
            else candidate[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> rec = {1,0,1,1};
    Solution* ss = new Solution;
    ss->containsNearbyDuplicate(rec, 1);

    return 0;
}
