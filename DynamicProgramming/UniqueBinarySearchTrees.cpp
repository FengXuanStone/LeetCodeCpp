//
// Created by fengxuan on 2016/8/28.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int result[n + 1] = {0};
        result[0] = 1;
        result[1] = 1;

        for(int i = 2; i <= n; ++i) {
            int tmp = 0;
            for(int j = 1; j <= i; ++j) {
                tmp += result[j - 1] * result[i - j];
            }

            result[i] = tmp;
        }

        return result[n];
    }
};

int main() {
    cout << "Hello world" << endl;

    strcmp("a","v");

    return 0;
}
