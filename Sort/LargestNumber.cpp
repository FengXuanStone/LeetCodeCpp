//
// Created by fengxuan on 2016/8/27.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> candidate;
        for(auto i = nums.cbegin(); i != nums.cend(); ++i) {
            candidate.push_back(to_string(*i));
        }

        sort(candidate.begin(), candidate.end(), [](string &s1, string & s2) {
            return s1 + s2 > s2 + s1;
        });

        string result;

        for(auto s : candidate) {
            result += s;
        }

        while(result[0]=='0' && result.length()>1)
            result.erase(0,1);
        return  result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
