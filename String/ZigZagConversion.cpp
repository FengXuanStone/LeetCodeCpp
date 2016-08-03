//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty())
            return "";
        if(numRows == 1)
            return s;

        stringstream oss;

        for(int i = 0; i < numRows; ++i) {
            int a = 2 * (numRows - 1 - i);
            int b = 2 * i;

            if(a == 0) {
                for(int j = i; j < s.size(); j += b) {
                    oss << s[j];
                }
            } else if(b == 0) {
                for(int j = i; j < s.size(); j += a) {
                    oss << s[j];
                }
            } else {
                for(int j = i; j < s.size();) {
                    oss << s[j];
                    j += a;
                    if(j < s.size()) oss << s[j];
                    j += b;
                }
            }
        }

        string result = oss.str();

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    ss->convert("abcdef", 3);

    return 0;
}
