//
// Created by fengxuan on 2016/9/2.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        result.push_back(tmp);
        push(result, tmp, nums, 0);

        return result;
    }

    void push(vector<vector<int>> &result, vector<int> &tmp, vector<int> & nums, int k) {
        for(int i = k; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            result.push_back(tmp);
            if(i + 1 < nums.size()) push(result, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<vector<int>> result;
        int max = 1<<nums.size();

        for(int i = 0; i < max; ++i) {
            vector<int> tmp;

            int idx = 0;
            int j = i;
            while (j > 0) {
                if(j&1) {
                    tmp.push_back(nums[idx]);
                }
                idx++;
                j >>= 1;
            }

            result.push_back(tmp);
        }

        return  result;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> vec{1,2,3};
    vector<vector<int>> result;

    Solution* ss = new Solution;
    result = ss->subsets(vec);

    for(int i = 0; i< result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << "\r\n";
    }

    cout << endl;

    return 0;
}
