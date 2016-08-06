//
// Created by fengxuan on 2016/8/6.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n > 10 || n < 0) return 0;
        if(n == 0) return 1;

        int result = 10;
        int tmp = 9;

        for(int i = 9; i > 9 - n + 1; --i) {
            tmp  *= i;
            result += tmp;
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}