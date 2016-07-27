//
// Created by fengxuan on 2016/7/27.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int result;

        while (num >= 10) {
            result = 0;
            while (num != 0) {
                result += num % 10;
                num = num / 10;
            }
            num = result;
        }
        return num;
    }

    int addDigits1(int num) {
        while(num>=10){
            num = (num/10)+num%10;
        }
        return num;
    }

    int addDigits2(int num) {
        return 1 + (num-1)%9;
    }
};

int main() {
    int a;
    cin >> a;

    Solution* ss = new Solution;
    int result = ss->addDigits(a);
    cout << result << endl;

    return 0;
}
