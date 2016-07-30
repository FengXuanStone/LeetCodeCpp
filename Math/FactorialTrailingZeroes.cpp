//
// Created by fengxuan on 2016/7/30.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;

        while (n / 5 != 0) {
            n /= 5;
            result += n;
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
