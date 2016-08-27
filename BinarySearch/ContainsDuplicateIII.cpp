//
// Created by fengxuan on 2016/8/25.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> bst;

        for(int i = 0; i < nums.size(); ++i) {
            if(bst.size() == k + 1) bst.erase(bst.find(nums[i - k - 1]));
            auto lb = bst.lower_bound(nums[i] - t);

            if(lb != bst.end() && *lb - nums[i] <= t) return true;

            bst.insert(nums[i]);
        }

        return false;
    }
};

int main() {
    cout << "Hello world" << endl;


    return 0;
}
