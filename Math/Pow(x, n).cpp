//
// Created by fengxuan on 2016/9/7.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        double tmp = x;
        long long int m = n;
        m = abs(m);
        bool k = n < 0;

        while (m) {
            if(m & 1) result *= tmp;

            tmp *= tmp;
            m >>= 1;
        }

        if(k) result = 1.0 / result;

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->myPow(1.00000,
                      -2147483648) << endl;

    return 0;
}
