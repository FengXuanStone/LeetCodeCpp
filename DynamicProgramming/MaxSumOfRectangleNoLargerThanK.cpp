//
// Created by fengxuan on 2016/9/17.
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
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int row = matrix.size(), col = matrix[0].size();
        int candidate[row][col];
        int result = INT32_MIN;

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                int tmp = matrix[i][j];
                if(i > 0) tmp += candidate[i - 1][j];
                if(j > 0) tmp += candidate[i][j - 1];
                if(i > 0 && j > 0) tmp -= candidate[i - 1][j - 1];
                candidate[i][j] = tmp;

                for(int a = 0; a <= i; ++a) {
                    for(int b = 0; b <= j; ++b) {
                        int x = candidate[i][j];

                        if(a > 0) x -= candidate[a - 1][j];
                        if(b > 0) x -= candidate[i][b - 1];
                        if(a > 0 && b > 0) x += candidate[a - 1][b - 1];

                        if(x <= k) result = max(result, x);
                    }
                }
            }
        }

        return result;
    }

    int maxSumSubmatrix1(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int row = matrix.size(), col = matrix[0].size();
        int result = INT32_MIN;

        for(int i = 0; i < col; ++i) {
            vector<int> sum(row, 0);

            for(int j = i; j < col; ++j) {
                for(int k = 0; k < row; ++k) {
                    sum[k] += matrix[k][j];
                }

                // Find the max subarray no more than K
                set<int> accuSet;
                accuSet.insert(0);
                int curSum = 0, curMax = INT32_MAX;
                for(int num : sum) {
                    curSum += num;
                    set<int>::iterator it = accuSet.lower_bound(curSum - k);
                    if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
                    accuSet.insert(curSum);
                }
                result = std::max(result, curMax);
            }
        }

        return result;
    }
};


int main() {
    cout << "Hello world" << endl;

    vector<vector<int>> res = {{2,2,-1}};
    Solution* ss = new Solution;
    cout << ss->maxSumSubmatrix(res, 3) << endl;

    return 0;
}
