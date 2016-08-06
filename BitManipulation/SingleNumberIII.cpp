//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int result = single(nums);
        int ss = 0;

        while (((result >> ss) & 1) == 0) ++ss;

        vector<int> vec1, vec2;
        for(int i = 0; i < nums.size(); ++i) {
            if(((nums[i] >> ss) & 1) == 0)
                vec1.push_back(nums[i]);
            else
                vec2.push_back(nums[i]);
        }

        vector<int> res;
        res.push_back(single(vec1));
        res.push_back(single(vec2));

        return res;
    }

    int single(vector<int>& nums) {
        int result = nums[0];

        for(int i = 1; i < nums.size(); ++i) {
            result = result ^ nums[i];
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    vector<int> vec{1,2,1,3,2,5};
    ss->singleNumber(vec);

    return 0;
}
