//
// Created by fengxuan on 2016/7/28.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;

        for(int i = 0; i < s.size(); ++i) {
            int tmp = s[i] - 64;
            result = result * 26 + tmp;
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    int result = ss->titleToNumber("AB");
    cout << result << endl;

    return 0;
}
