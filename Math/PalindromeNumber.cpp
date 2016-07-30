//
// Created by fengxuan on 2016/7/30.
//
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return  false;

        int tmp = x;
        int len = 1;
        while (tmp / 10 != 0) {
            tmp /= 10;
            len = len * 10;
        }

        int j = 1;
        for(int i = 0; i < len / 2; ++i) {
            int x1 = (x / len) % 10;
            int x2 = (x / j) % 10;
            if(x1 != x2) {
                return false;
            } else {
                len = len / 10;
                j = j * 10;
            }
        }

        return true;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    ss->isPalindrome(0);

    return 0;
}
