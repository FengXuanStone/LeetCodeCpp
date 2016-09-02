//
// Created by fengxuan on 2016/9/1.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;

        int row = matrix.size(), col = matrix[0].size();
        bool r = false, l = false;

        for(int i = 0; i < row; ++i) {
            if(r || matrix[i][0] == 0) r = true;
        }
        for(int i = 0; i < col; ++i) {
            if(l || matrix[0][i] == 0) l = true;
        }

        for(int i = 1; i < row; ++i) {
            for(int j = 1; j < col; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < row; ++i) {
            for(int j = 1; j < col; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if(r) {
            for(int i = 0; i < row; ++i) matrix[i][0] = 0;
        }

        if(l) {
            for(int i = 0; i < col; ++i) matrix[0][i] = 0;
        }

    }
};

int main() {
    cout << "Hello world" << endl;

    vector<vector<int>> vec = {{5},{2},{0},{3},{6},{7},{2}};
    Solution* ss = new Solution;
    ss->setZeroes(vec);

    for(int i = 0; i < vec.size(); ++i) {
        for(int j = 0; j < vec[0].size(); ++j) {
            cout << vec[i][j] << ' ';
        }
        cout << "\r\n";
    }

    cout << endl;

    return 0;
}
