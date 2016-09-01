//
// Created by fengxuan on 2016/8/31.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;

        int row = matrix.size();
        int round = (row + 1) / 2;

        for(int i = 0; i < round; ++i) {
            for(int j = i; j < row - i - 1; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[row - j - 1][i];
                matrix[row - j - 1][i] = matrix[row - i - 1][row - j - 1];
                matrix[row - i - 1][row - j - 1] = matrix[j][row - i - 1];
                matrix[j][row - i - 1] = tmp;
            }
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<vector<int>> vec{{1,2,3},{4,5,6},{7,8,9}};
    Solution* ss = new Solution;
    ss->rotate(vec);

    for(auto i : vec) {
        for(auto j : i)
            cout << j << ' ';
    }

    return 0;
}
