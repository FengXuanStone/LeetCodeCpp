//
// Created by fengxuan on 2016/9/3.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();

        if(row == 0) return 0;
        int col = triangle[row - 1].size();

        vector<int> candidate = triangle[row - 1];
        --col;

        for(int i = row - 2; i >= 0; --i) {
            for(int j = 0; j < col; ++j) {
                candidate[j] = min(candidate[j], candidate[j + 1]) + triangle[i][j];
            }
            --col;
        }

        return candidate[0];
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
