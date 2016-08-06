//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = *nums.cbegin();

        for(auto i = nums.cbegin() + 1; i != nums.cend(); ++i) {
            result = result ^ *i;
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
