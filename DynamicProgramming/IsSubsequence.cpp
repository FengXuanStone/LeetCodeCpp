//
// Created by fengxuan on 2016/9/17.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        if(t.empty()) return false;

        int index = 0, size = t.size(), sSize = s.size();
        for(int i = 0; i < size; ++i) {
            if(s[index] == t[i]) ++index;
            if(sSize == index) break;
        }

        if(sSize == index) return true;
        else return false;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
