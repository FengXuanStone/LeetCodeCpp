//
// Created by fengxuan on 2016/8/9.
//
#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        stack<string> candidate;
        if(s.empty()) return;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') continue;

            string tmp;

            while (i < s.size() && s[i] != ' ') {
                tmp += s[i];
                ++i;
            }

            candidate.push(tmp);
        }

        if(candidate.empty()) {
            s = "";
        } else {
            s.clear();
            while (!candidate.empty()) {
                s += candidate.top();
                candidate.pop();
                s += ' ';
            }
            s.erase(s.end() - 1);
        }

    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    string s = "   a  b  ";
    ss->reverseWords(s);

    cout << "-" << s  << "-" << endl;

    return 0;
}
