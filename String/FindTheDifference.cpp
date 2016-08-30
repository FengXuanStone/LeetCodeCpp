//
// Created by fengxuan on 2016/8/28.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int candidate[32] = {0};

        int i = 0;
        for(; i < s.size(); ++i) {
            --candidate[(s[i] - 'a')];
            ++candidate[(t[i] - 'a')];
        }
        ++candidate[(t[i] - 'a')];

        for(i = 0; i < 32; ++i) {
            if(candidate[i] == 1) return (char)(i + 'a');
        }

        return ' ';
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;

    return 0;
}
