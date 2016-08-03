//
// Created by fengxuan on 2016/8/1.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        auto ai = a.size();
        auto bj = b.size();

        if(ai == 0) return b;
        if(bj == 0) return a;

        stringstream s;

        int carry = 0;

        while (ai > 0 || bj > 0) {
            if(ai == 0) {
                int tmp = (b[bj - 1] - '0') + carry;
                s << (tmp % 2);
                carry = tmp / 2;
                --bj;
            } else if(bj == 0) {
                int tmp = ( a[ai - 1] - '0') + carry;
                s << (tmp % 2);
                carry = tmp / 2;
                --ai;
            } else {
                int tmp = ( a[ai - 1] - '0') + (b[bj - 1] - '0') + carry;
                s << (tmp % 2);
                carry = tmp / 2;
                --ai;
                --bj;
            }
        }

        if(carry) s << "1";

        string str = s.str();

        reverse(str.begin(), str.end());

        return str;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->addBinary("0", "0") << endl;

    return 0;
}
