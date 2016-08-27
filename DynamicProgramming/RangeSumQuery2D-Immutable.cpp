//
// Created by fengxuan on 2016/8/27.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int col;
        if(row <= 0) return;
        else col = matrix[0].size();

        for(int i = 0; i < row; ++i) {
            vector<int> tmp(col);
            countMatrix.push_back(tmp);
        }

        countMatrix[0][0] = matrix[0][0];
        for(int i = 1; i < row; ++i) countMatrix[i][0] = countMatrix[i - 1][0] + matrix[i][0];
        for(int i = 1; i < col; ++i) countMatrix[0][i] = countMatrix[0][i - 1] + matrix[0][i];

        for(int i = 1; i < row; ++i) {
            for(int j = 1; j < col; ++j) {
                countMatrix[i][j] =
                        countMatrix[i][j - 1] + countMatrix[i - 1][j] - countMatrix[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0) {
            return countMatrix[row2][col2];
        } else if(row1 == 0) {
            return countMatrix[row2][col2] - countMatrix[row2][col1 - 1];
        } else if(col1 == 0) {
            return countMatrix[row2][col2] - countMatrix[row1 - 1][col2];
        } else {
            return countMatrix[row2][col2] - countMatrix[row1 - 1][col2] - countMatrix[row2][col1 - 1] + countMatrix[row1 - 1][col1 - 1];
        }
    }

private:
    vector<vector<int>> countMatrix;
};

int main() {
    cout << "Hello world" << endl;

    vector<vector<int>> res = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};

    NumMatrix* ss = new NumMatrix(res);
    cout << ss->sumRegion(2, 1, 4, 3);
    cout << ss->sumRegion(1, 1, 2, 2);
    cout << ss->sumRegion(1, 2, 2, 4);
    return 0;
}
