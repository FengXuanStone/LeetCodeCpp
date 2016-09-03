//
// Created by fengxuan on 2016/9/3.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        result.push_back(tmp);
        int n = nums.size();

        sort(nums.begin(), nums.end());
        if(n == 0) return result;
        subSets(result, tmp, nums, n, 0);

        return result;
    }

    void subSets(vector<vector<int>> &result, vector<int> &tmp, vector<int> &nums, int n, int k) {
        for(int i = k; i < n; ++i) {
            tmp.push_back(nums[i]);
            if(i == k || nums[i] != nums[i - 1]) {
                result.push_back(tmp);
                subSets(result, tmp, nums, n, i + 1);
            }

            tmp.pop_back();
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<vector<int>> result;
    vector<int> vec{4,4,4,1,4};
    Solution* ss = new Solution;

    result = ss->subsetsWithDup(vec);

    for(int i = 0; i< result.size(); ++i) {
        for(int j= 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << "\r\n";
    }
    cout << endl;


    return 0;
}
