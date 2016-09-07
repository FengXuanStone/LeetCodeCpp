//
// Created by fengxuan on 2016/9/6.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <stack>

using namespace std;
class Solution {
public:
    int cal_help(int left, int right, char syn) {
        switch (syn) {
            case '*' : return left * right;
            case '/': return left / right;
            default: return 0;
        }
    }

    int calculate(string s) {
        stack<int> numbers;
        stack<char> symbol;
        symbol.push('+');
        int n = s.size();

        for(int i = 0; i < n; ) {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                symbol.push(s[i++]);
            } else if(s[i] == ' '){
                i++;
            } else {
                int tmp = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    tmp = tmp * 10 + s[i] - '0';
                    ++i;
                }
                if(!symbol.empty() && (symbol.top() != '+') && (symbol.top() != '-')) {
                    tmp = cal_help(numbers.top(), tmp, symbol.top());
                    symbol.pop();
                    numbers.pop();
                }
                numbers.push(tmp);
            }
        }

        int result = 0;

        while (!numbers.empty()) {
            int tmp = numbers.top();
            if(symbol.top() == '-') {
                tmp = -tmp;
            }

            result += tmp;

            numbers.pop();
            symbol.pop();
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    string s = "1-1+1";
    Solution* ss = new Solution;
    cout <<  ss->calculate(s) << endl;

    return 0;
}
