//
// Created by fengxuan on 2016/7/28.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> tmp;

        for(int i = 0; i < nums.size(); ++i) {
            tmp.insert(nums[i]);
        }

        return tmp.size() != nums.size();
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
