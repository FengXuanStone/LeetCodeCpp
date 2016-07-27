//
// Created by fengxuan on 2016/7/27.
//
#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main() {
    int a;
    cin >> a;

    Solution* ss = new Solution;
    bool result = ss->canWinNim(a);
    cout << result << endl;

    return 0;
}
