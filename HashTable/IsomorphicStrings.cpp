//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        map<char, char> candidate;
        map<char, char> reverse_can;

        for(int i = 0; i < s.size(); ++i) {
            char a = s[i];
            char b = t[i];

            if(candidate.find(a) != candidate.end() && reverse_can.find(b) != reverse_can.end()) {
                if(candidate[a] != b || reverse_can[b] != a) return false;
            } else if(candidate.find(a) != candidate.end() || reverse_can.find(b) != reverse_can.end()) {
                return false;
            }  else {
                candidate.insert(pair<char, char>(a, b));
                reverse_can.insert(pair<char, char>(b,a));
            }
        }

        return true;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    ss->isIsomorphic("ab", "aa");

    return 0;
}
