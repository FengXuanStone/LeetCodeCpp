//
// Created by fengxuan on 2016/7/27.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0)
        {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};

int main() {
    int a, b;
    cin >> a >> b;

    Solution* ss = new Solution;
    int result = ss->getSum(a, b);
    cout << result << endl;

    return 0;
}
