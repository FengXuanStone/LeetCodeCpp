//
// Created by fengxuan on 2016/7/28.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram1(string s, string t) {
        vector<int> count(26, 0);

        for(auto i = s.begin(); i != s.end(); ++i) {
            count[*i-'a']++;
        }
        for(auto i = t.begin(); i != t.end(); ++i) {
            count[*i-'a']--;
        }
        for(int i = 0; i < 26; i ++)
            if(count[i] != 0)
                return false;
        return true;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
