//
// Created by fengxuan on 2016/8/7.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(k <= 0) return 0;

        int left = matrix[0][0], right = matrix.back().back();

        while(left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int i =0; i < matrix.size(); ++i) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if(count < k) left = mid + 1;
            else right = mid;
        }

        return left;
    }

    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        if(k <= 0) return 0;

        priority_queue<int, vector<int>> q;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix.size(); ++j) {
                q.push(matrix[i][j]);
                if(q.size() > k) q.pop();
            }
        }

        return q.top();
    }
};

int main() {
    cout << "Hello world" << endl;
    Solution* ss = new Solution;

    vector<vector<int>> tmp = {{1,2}, {1,3}};

    ss->kthSmallest(tmp, 3);

    return 0;
}
