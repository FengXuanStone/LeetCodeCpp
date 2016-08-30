//
// Created by fengxuan on 2016/8/7.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};
        int result = 0;
        for(int i = 0; i < 32; ++i) {
            for(int j = 0; j < nums.size(); ++j) {
                if((nums[j] >> i) & 1) count[i]++;
            }
            result |= ((count[i] % 3) << i);
        }

        return result;
    }

    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, threes = 0;

        for(int i = 0; i < nums.size(); ++i) {
            //出现了一次的和第i个数每一位上都出现了一次的，一共出现了两次。与出现了两次的求或
            twos |= ones & nums[i];
            ones ^= nums[i];
            //三次等于一次加两次
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }

        return ones;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
