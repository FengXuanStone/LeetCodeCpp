//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); ++i) {
            if(st.empty()) {
                st.push(s[i]);
            } else if((s[i] == ')' && st.top() == '(') ||
                    (s[i] == ']' && st.top() == '[') ||
                    (s[i] == '}' && st.top() == '{')) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;

    return 0;
}
