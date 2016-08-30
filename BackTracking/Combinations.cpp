//
// Created by fengxuan on 2016/8/30.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;

        if(k <= 0 || n <= 0) return result;

        vector<int> tmp;

        combination(result, tmp, n, k, 1);

        return result;
    }

    void combination(vector<vector<int>> &result, vector<int> &tmp, int n, int k, int index) {
        if(index > n) return;

        for(int i = index; i <= n; ++i) {
            tmp.push_back(i);

            if(tmp.size() == k) {
                result.push_back(tmp);
            } else {
                combination(result, tmp, n, k, i + 1);
            }

            tmp.pop_back();
        }
    }
    //方法2设计十分精巧
    vector<vector<int>> combine1(int n, int k) {
        vector<vector<int>> result;
        if(k <= 0 || n <= 0) return result;
        vector<int> tmp(k, 0);

        int i = 0;
        while (i >= 0) {
            tmp[i]++;
            if(tmp[i] > n) --i;
            else if(i == k - 1) result.push_back(tmp);
            else {
                ++i;
                tmp[i] = tmp[i - 1];
            }
        }
        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    auto xxx = ss->combine1(4,2);

    for(int i = 0; i < xxx.size(); ++i) {
        for(int j = 0; j < xxx[i].size(); ++j) {
            cout << xxx[i][j] << ' ';
        }
        //cout << '\r\n';
    }

    cout << endl;

    return 0;
}
