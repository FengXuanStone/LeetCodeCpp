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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        vector<int> tmp(n, 0);
        for(int i = 0; i < n; ++i) {
            result.push_back(tmp);
        }

        int x = 1;
        int round = (n + 1) / 2;
        for(int i = 0; i <= round; ++i) {
            int leftRow = i, leftCol = i, rightRow = n - i - 1, rightCol = n - i - 1;

            if(leftCol == rightCol) result[leftRow][leftCol] = x++;
            else {
                for(int j = leftCol; j < rightCol; ++j) result[leftRow][j] = x++;
                for(int j = leftRow; j < rightRow; ++j) result[j][rightCol] = x++;
                for(int j = rightCol; j > leftCol; --j) result[rightRow][j] = x++;
                for(int j = rightRow; j > leftRow; --j) result[j][leftCol] = x++;
            }
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    int n = 4;
    Solution* ss = new Solution;
    auto result = ss->generateMatrix(n);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            cout << result[i][j] << ' ';
        cout << "\r\n";
    }

    return 0;
}
