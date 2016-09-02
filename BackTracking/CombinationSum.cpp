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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> tmp;

        combination(result, tmp, candidates, target, 0, 0);

        return result;
    }

    void combination(vector<vector<int>> &result, vector<int> & tmp, vector<int> &candidates, int target, int sum, int k) {
        for(int i = k; i < candidates.size(); ++i) {
            int num = sum + candidates[i];

            if(num == target) {
                tmp.push_back(candidates[i]);
                result.push_back(tmp);
                tmp.pop_back();
            } else if(num < target) {
                tmp.push_back(candidates[i]);
                combination(result, tmp, candidates, target, num, i);
                tmp.pop_back();
            } else continue;
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<vector<int>> result;
    vector<int> candidates{2,3,6,7};

    Solution* ss = new Solution;
    result = ss->combinationSum(candidates, 7);

    for(int i = 0;i < result.size(); ++i) {
        for(int j= 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << "\r\n";
    }
    cout << endl;

    return 0;
}
