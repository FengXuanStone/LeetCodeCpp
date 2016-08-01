//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> candidate;
        map<string, char> rev_candidate;
        vector<string> vec;
        istringstream sin(str);

        string s;
        while (sin >> s) { vec.push_back(s); }

        if(vec.size() != pattern.size()) return false;

        for(int i = 0; i < pattern.size(); ++i) {
            if(candidate.find(pattern[i]) == candidate.end()) {
                candidate.insert(pair<char, string>(pattern[i], vec[i]));
            } else if(candidate[pattern[i]] != vec[i]) return false;

            if(rev_candidate.find(vec[i]) == rev_candidate.end()) {
                rev_candidate.insert(pair<string, char>(vec[i], pattern[i]));
            } else if(rev_candidate[vec[i]] != pattern[i]) return false;
        }

        return true;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
