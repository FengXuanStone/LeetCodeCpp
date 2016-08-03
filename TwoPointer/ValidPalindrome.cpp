//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            bool a = isAlphanumeric(s[i]);
            bool b = isAlphanumeric(s[j]);

            if(a && b) {
                if(s[i] != s[j]) return false;
                ++i;
                --j;
            } else if(a) {
              --j;
            } else if(b) {
                ++i;
            } else {
                ++i;
                --j;
            }
        }

        return true;
    }

    bool isAlphanumeric(char& c) {
        if(c >= 'a' && c <= 'z') return true;
        if(c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
            return true;
        }
        if(c >= '0' && c <= '9') return true;
        return false;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
