//
// Created by fengxuan on 2016/8/1.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.empty()) return -1;
        if(needle.size() > haystack.size()) return -1;

        int i = 0;
        for(; i < haystack.size() - needle.size() + 1; ++i) {
            bool flag = true;
            for(int j = 0; j < needle.size(); ++j) {
                if(flag && haystack[i + j] != needle[j])  flag = false;
            }
            if(flag) break;
        }

        int k = i == (haystack.size() - needle.size() + 1) ? -1 : i;

        return k;
    }

    int strStr_KMP(string haystack, string needle) {

    }

    int* next(string needle) {
        int result[needle.size()];


    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    ss->strStr("a","a");

    return 0;
}
