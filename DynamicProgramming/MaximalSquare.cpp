//
// Created by fengxuan on 2016/9/18.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int row = matrix.size(), col = matrix[0].size();
        int result = 0;

        vector<vector<int>> dp(row, vector<int>(col, 0));

        for(int i = 0; i < row; ++i) {

        }
    }
};

int main() {
    cout << "Hello world" << endl;


    return 0;
}
