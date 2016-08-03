//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {

public:
    int myAtoi(string str) {
        long long result = 0;
        bool minus=false;
        int i = 0;

        if(str.empty()) return 0;

        while (str[i] == ' ') ++i;
        if(str[i] == '-') {
            minus = true;
            ++i;
        } else if(str[i] == '+') ++i;

        for(; i < str.size(); ++i) {
            if(str[i] >= '0' && str[i] <= '9') {
                if(minus) {
                    result = result * 10 - (str[i] - '0');
                    if(result<-2147483648) return -2147483648;
                } else {
                    result = result * 10 + (str[i] - '0');
                    if(result>2147483647) return 2147483647;
                }
            } else break;
        }

        int res = (int)result;
        return res;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
