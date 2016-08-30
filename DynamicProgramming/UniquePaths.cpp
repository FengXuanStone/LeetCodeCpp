//
// Created by fengxuan on 2016/8/29.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> candidate(n, 1);

        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                candidate[j] = candidate[j] + candidate[j - 1];
            }
        }

        return candidate[candidate.size() - 1];
    }
};

int main() {
    cout << "Hello world" << endl;

    strcmp("a","v");

    return 0;
}
