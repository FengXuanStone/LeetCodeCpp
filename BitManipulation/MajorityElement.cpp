//
// Created by fengxuan on 2016/7/28.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(count == 0) {
                candidate = nums[i];
                count++;
            } else {
                if(nums[i] == candidate) {
                    count++;
                } else
                    count--;
            }
        }

        return candidate;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
