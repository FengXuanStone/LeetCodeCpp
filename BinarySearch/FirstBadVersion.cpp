//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <algorithm>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int first = 1;
        int second = n;

        while (first < second) {
            int mid = first + (second - first) / 2;
            if(!isBadVersion(mid)) {
                first = mid + 1;
            } else {
                second = mid - 1;
            }
        }

       if(!isBadVersion(first)) return first + 1;
       else return first;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
