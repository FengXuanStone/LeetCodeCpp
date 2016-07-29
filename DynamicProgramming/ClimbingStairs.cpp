//
// Created by fengxuan on 2016/7/29.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return n;

        int a = 1, b = 2;
        n--;

        while (n--) {
            b = a + b;
            a = b - a;
        }

        return a;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;

    cout << ss->climbStairs(2) << endl;

    return 0;
}
