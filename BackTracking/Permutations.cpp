//
// Created by fengxuan on 2016/8/29.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;

        insert(nums, tmp, result);

        return result;
    }

    void insert(vector<int> &num, vector<int> & tmp, vector<vector<int>> & result) {
        if(num.size() == 1) {
            tmp.push_back(num[0]);
            result.push_back(tmp);
            tmp.pop_back();
        }
        else {
            int n = num.size();
            for(int i = 0; i < n; ++i) {
                int k = num[i];
                tmp.push_back(k);
                num.erase(num.begin() + i);
                insert(num, tmp, result);
                tmp.pop_back();
                num.insert(num.begin() + i, k);
            }
        }
    }

    vector<vector<int>> permute1(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;

        insert1(nums, 0, result);

        return result;
    }

    void insert1(vector<int> &num, int begin, vector<vector<int>> & result) {
        if(begin >= num.size()) {
            result.push_back(num);
            return;
        }

        for(int i = begin; i < num.size(); ++i) {
            swap(num[begin], num[i]);
            insert1(num, begin + 1, result);
            swap(num[begin], num[i]);
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    vector<int> nums{1,2,3,4};

    ss->permute(nums);

    return 0;
}
