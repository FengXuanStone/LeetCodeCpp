//
// Created by fengxuan on 2016/7/28.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;

        while (n > 0) {
            n = n & (n - 1);
            ++result;
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
