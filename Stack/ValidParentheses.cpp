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
            if((s[i] == ')' && st.top() == '(') ||
                    (s[i] == ')' && st.top() == '(') ||
                    (s[i] == ')' && st.top() == '(')) {

            }
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
