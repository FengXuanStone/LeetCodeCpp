//
// Created by fengxuan on 2016/8/28.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> candidate;

        combination(result, candidate, k, n);

        return result;
    }

    void combination(vector<vector<int>> &result, vector<int> candidate, int k, int n) {
        if(candidate.size() == k && n == 0) {
            result.push_back(candidate);
            return;
        }
        if(candidate.size() < k) {
            for(int i = (candidate.empty() ? 1 : candidate.back() + 1); i < 10; ++i) {
                if((n - i) < 0) break;
                candidate.push_back(i);
                combination(result, candidate, k, n - i);
                candidate.pop_back();
            }
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    strcmp("a","v");

    return 0;
}
