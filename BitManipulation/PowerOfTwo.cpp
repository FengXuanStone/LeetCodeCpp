//
// Created by fengxuan on 2016/7/28.
//
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ((n & (n - 1)) == 0);
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
