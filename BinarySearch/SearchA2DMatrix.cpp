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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;

        int row = matrix.size(), col = matrix[0].size();

        if(target < matrix[0][0] || target > matrix[row - 1][col - 1])
            return false;

        int left = 0, right = row;
        int mid = left + (right - left) / 2;

        while (left < right) {
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] > target) right = mid;
            else left = mid + 1;

            mid = left + (right - left) / 2;
        }

        int r = left - 1;
        left = 0; right = col;
        mid = left + (right - left) / 2;

        while (left < right) {
            if(matrix[r][mid] == target) return true;
            else if(matrix[r][mid] > target) right = mid;
            else left = mid + 1;

            mid = left + (right - left) / 2;
        }

        return false;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<vector<int>> mat{{1,3}};
    Solution* ss = new Solution;
    cout << ss->searchMatrix(mat, 2) << endl;

    return 0;
}
