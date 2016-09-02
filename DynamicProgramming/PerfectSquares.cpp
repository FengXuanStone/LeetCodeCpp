//
// Created by fengxuan on 2016/9/2.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if(n == 0) return 0;

        vector<int> candidate;
        candidate.push_back(0);
        candidate.push_back(1);

        for(int i = 2; i <= n; ++i) {
            int minV = INT_MAX;
            int j = 1;
            int doubleJ = j * j;

            while (doubleJ <= i) {
                if(doubleJ == i) {
                    minV = 1;
                    break;
                } else {
                    minV = min(minV, candidate[i - doubleJ] + 1);
                    j++;
                    doubleJ = j * j;
                }
            }
            candidate.push_back(minV);
        }

        return candidate[n];
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;

    cout << ss->numSquares(4) << endl;
    return 0;
}
