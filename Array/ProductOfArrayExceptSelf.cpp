//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        if(nums.empty()) return result;

        int tmp = 1;
        result.push_back(tmp);

        for(int i = 1; i < nums.size(); ++i) {
            tmp = tmp * nums[i - 1];
            result.push_back(tmp);
        }

        tmp = 1;

        for(int i = nums.size() - 2; i >= 0; --i) {
            tmp = tmp * nums[i + 1];
            result[i] = result[i] * tmp;
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
