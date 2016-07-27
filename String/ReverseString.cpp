//
// Created by fengxuan on 2016/7/27.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string str(s.rbegin(), s.rend());
        return str;
    }

    string reverseString1(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};

int main() {
    string s;
    cin >> s;

    auto solutione = new Solution;
    string ss = solutione->reverseString(s);

    cout << ss << endl;

    return 0;
}
