//
// Created by fengxuan on 2016/7/28.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = toNumber(s[0]);

        for(int i = 1; i < s.size(); ++i) {
            int index = toNumber(s[i]);
            int preIndex = toNumber(s[i - 1]);

            if(preIndex < index) {
                result += index - 2 * preIndex;
            } else {
                result += index;
            }
        }

        return result;
    }

    int toNumber(char ch) {
        switch (ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }

        return 0;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
