//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return NULL;

        string s = "1";

        while (--n) {
            s = getStr(s);
        }

        return s;
    }

    string getStr(string s) {
        stringstream ss;
        int count = 0;
        char find = s[0];

        for(int i = 0; i < s.size(); ++i) {
            if(find == s[i]) {
                ++count;
            } else {
                ss << count << find;
                count = 1;
                find = s[i];
            }
        }

        ss << count << find;

        return ss.str();
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->countAndSay(2) << endl;

    return 0;
}
