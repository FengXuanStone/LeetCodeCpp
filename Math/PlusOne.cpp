//
// Created by fengxuan on 2016/7/30.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for(int i = digits.size() - 1; i >= 0; --i) {
            int tmp = digits[i] + carry;
            digits[i] = tmp % 10;
            carry = tmp / 10;
        }

        if(carry == 1) digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
