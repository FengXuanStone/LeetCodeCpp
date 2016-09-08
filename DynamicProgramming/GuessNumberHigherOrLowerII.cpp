//
// Created by fengxuan on 2016/9/3.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

int guess(int num);

class Solution {
public:
    int getMoneyAmount(int n) {
        if(n == 1)
            return  0;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int i = n; i > 0; --i) {
            for(int j = i + 1; j <= n; ++j) {
                    dp[i][j] = INT_MAX;

                    for(int k = i; k <= j; ++k) {
                        int a = k - 1 >= i ? dp[i][k - 1] : 0;
                        int b = j >= k + 1 ? dp[k + 1][j] : 0;

                        dp[i][j] = min(dp[i][j], k + max(a, b));
                    }
                }
            }
        return dp[1][n];
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->getMoneyAmount(3) << endl;

    return 0;
}
