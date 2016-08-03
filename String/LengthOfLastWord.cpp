//
// Created by fengxuan on 2016/8/1.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;

        int i = s.size();
        while (s[i - 1] == ' ') --i;

        int j = i;
        for(; j > 0; --j) {
            if(s[j - 1] == ' ') break;
        }

        return i - j;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->lengthOfLastWord("a ") << endl;

    return 0;
}
