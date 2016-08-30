//
// Created by fengxuan on 2016/8/30.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    bool isPerfectSquare1(int num) {
        long left = 1, right = num;

        while (left <= right) {
            long mid = left + (right - left) / 2;
            long tmp = num / mid;

            if(tmp == mid) return num % mid == 0;
            else if(tmp > mid) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }

    bool isPerfectSquare(int num) {
        int i = 1;

        while(num > 0) {
            num -= i;
            i += 2;
        }

        return num == 0;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->isPerfectSquare1(5) << endl;

    return 0;
}
