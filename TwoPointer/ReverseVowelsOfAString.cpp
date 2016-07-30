//
// Created by fengxuan on 2016/7/29.
//
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int i = 0;
        int j = s.size() - 1;

        while(i <= j) {
            auto b1 = vowels.find(s[i]) == vowels.end();
            auto b2 = vowels.find(s[j]) == vowels.end();
            if(b1 && b2) {
                ++i;
                --j;
            } else if(b1) {
                ++i;
            } else if(b2) {
                --j;
            } else {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                ++i;
                --j;
            }
        }

        return s;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout <<  ss->reverseVowels("leetcode") << endl;

    return 0;
}
