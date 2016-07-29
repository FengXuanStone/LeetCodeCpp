//
// Created by fengxuan on 2016/7/28.
//
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && (n % 3 == 0)) n /= 3;
        return n == 1;
    }

    bool isPowerOfThree1(int n) {
        return (n > 0 && 1162261467 % n == 0);
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
