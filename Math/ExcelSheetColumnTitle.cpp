//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        if(n == 0) return "";

        stringstream oss;

        while (n != 0) {
            char tmp = (char)('A' + (n - 1) % 26);
            oss << tmp;
            n = (n - 1) / 26;
        }

        string s = oss.str();
        reverse(s.begin(), s.end());

        return s;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
