//
// Created by fengxuan on 2016/8/20.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) {
            if(s[0] == '0') return 0;
            else return 1;
        }

        int pre = s[0] == '0' ? 0 : 1;
        int cur = 0;

        int num = (s[0] - '0') * 10 + (s[1] - '0');
        if(num == 0) return 0;
        if(num < 10) {
            cur = 0;
        }  else if(num <= 26){
            cur = (s[1] == '0') ? 1 : 2;
        } else if(s[1] == '0') {
            return 0;
        }  else cur = 1;

        for(int i = 2; i < s.size(); ++i) {
            num = (s[i - 1] - '0') * 10 + (s[i] - '0');

            int tmp = 0;
            if(num == 0) return 0;

            if(num < 10) {
                tmp = cur;
            }  else if(num <= 26){
                tmp = (s[i] == '0') ? pre : pre + cur;
            } else if(s[i] == '0') {
                return 0;
            }  else tmp = cur;

            pre = cur;
            cur = tmp;
        }

        return cur;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
