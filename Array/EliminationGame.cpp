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
    int lastRemaining(int n) {
        int count = n;
        int start = 1;
        int step = 2;
        bool left = true;

        while (count > 1) {
            count = count / 2;

            if(left) {
                start = start + step * count - step / 2;
            } else {
                start = start - step * count + step / 2;
            }

            step *= 2;
            left = !left;
        }

        return start;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->lastRemaining(11);

    return 0;
}
