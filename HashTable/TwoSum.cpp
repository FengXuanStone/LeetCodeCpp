//
// Created by fengxuan on 2016/7/30.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> candidate;
        vector<int> result;

        for(int i = 0; i < nums.size(); ++i) {
            int a = nums[i], b = target - nums[i];

            if(candidate.find(b) != candidate.end()) {
                result.push_back(candidate[b]);
                result.push_back(i);
                break;
            }

            if(candidate.find(a) == candidate.end()) {
                candidate.insert(pair<int ,int>(a,i));
            }
        }

        if(result.empty()) {
            result.push_back(1);
            result.push_back(2);
        }

        return result;
    }

    vector<int> twoSum1(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        for(int i = 0, j = nums.size() - 1; i > j;) {
            int tmp = nums[i] = nums[j];
            if(tmp > target) {
                --j;
            } else if(tmp < target) {
                ++i;
            } else {
                return vector<int>{i,j};
            }
        }

        return vector<int>{};
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
