//
// Created by fengxuan on 2016/8/1.
//
#include <iostream>
#include <bits/stl_vector.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty() || strs[0].empty()) return "";

        for(int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); ++j) {
                if(strs[j].size() == i || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
