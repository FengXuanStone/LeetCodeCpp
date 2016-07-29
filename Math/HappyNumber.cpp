//
// Created by fengxuan on 2016/7/29.
//
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int power[]{0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

        if(n < 1) return false;
        if(n == 1) return true;

        set<int> visited;

        while (true) {
            int result = 0;
            while (n > 0) {
                result += power[n % 10];
                n = n / 10;
            }

            if(result == 1) return true;
            else if(visited.find(result) != visited.end()) {
                return false;
            }
            n = result;
            visited.insert(result);
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;

    auto yy = ss->isHappy(19);

    cout << yy << endl;

    return 0;
}
