//
// Created by fengxuan on 2016/8/30.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;

        auto row = grid.size();
        auto col = grid[0].size();
        vector<int> candidate(col, INT_MAX);
        candidate[0] = 0;

        for(int i = 0; i < row; ++i) {
            candidate[0] = candidate[0] + grid[i][0];

            for(int j = 1; j < col; ++j) {
                candidate[j] = candidate[j] > candidate[j - 1] ? candidate[j - 1] : candidate[j];
                candidate[j] += grid[i][j];
            }
        }

        return candidate[candidate.size() - 1];
    }
};

int main() {
    cout << "Hello world" << endl;

    strcmp("a","v");

    return 0;
}
