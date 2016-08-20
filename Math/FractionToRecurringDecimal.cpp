//
// Created by fengxuan on 2016/8/9.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        if(denominator == 0) return "";

        string result;

        if((numerator < 0) ^ (denominator < 0)) result += "-";

        long long int s1 = numerator;
        long long int s2 = denominator;
        s1 = abs(s1);
        s2 = abs(s2);

        long long int res = s1 / s2;
        result += to_string(res);

        long long int tmp = s1 % s2;
        if(tmp == 0) return result;
        else result += '.';

        map<int, int> candidate;

        while (tmp) {
            if(candidate.find(tmp) != candidate.end()) {
                result.insert(candidate[tmp],1,'(');
                result+=')';
                break;
            }
            candidate[tmp] = result.size();

            tmp *= 10;
            string ssss = to_string(tmp / s2);
            result += to_string(tmp / s2);
            tmp = tmp % s2;
        }

        return result;
    }
};

int main() {
    cout << "Hello world1" << endl;

    Solution * ss = new Solution;
    cout << ss->fractionToDecimal(-1, -2147483648) << endl;

    return 0;
}
