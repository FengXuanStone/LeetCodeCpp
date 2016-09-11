//
// Created by fengxuan on 2016/9/9.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        if(row == 0) return 0;
        int col = obstacleGrid[0].size();

        vector<vector<int>> result(row, vector<int>(col, 0));
        result[0][0] = !obstacleGrid[0][0];

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(i == 0 && j == 0) continue;
                if(obstacleGrid[i][j] == 1) result[i][j] = 0;
                else {
                    int a = i == 0 ? 0 : result[i - 1][j];
                    int b = j == 0 ? 0 : result[i][j - 1];
                    result[i][j] = (a + b);
                }
            }
        }

        return result[row - 1][col - 1];
    }
};

int main() {
    cout << "Hello world" << endl;
    vector<vector<int>> vec{vector<int>{0}};
    Solution* ss = new Solution;
    cout << ss->uniquePathsWithObstacles(vec) << endl;

    return 0;
}
