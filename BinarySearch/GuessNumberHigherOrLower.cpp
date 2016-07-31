//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>

using namespace std;

int guess(int num) {
    if(num == 6) return 0;
    else if(num > 6) return -1;
    else return 1;
};

class Solution {
public:
    int guessNumber(int n) {
        int left = 0;
        int right = n;

        while (left <= right) {
            int mid = left + (right-left) / 2;
            int tag = guess(mid);
            switch (tag) {
                case 0:
                    return mid;
                case 1:
                    left = mid + 1;
                    break;
                case -1:
                    right = mid - 1;
                    break;
                default:
                    break;
            }
        }

        return 0;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->guessNumber(10) << endl;

    return 0;
}
