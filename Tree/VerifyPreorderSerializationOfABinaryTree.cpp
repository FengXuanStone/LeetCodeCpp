//
// Created by fengxuan on 2016/9/2.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:

    bool isValidSerialization(string preorder) {
        vector<char> candidate;
        int n = preorder.size();
        if(n == 0) return true;

        for(int i = 0; i < n;) {
            candidate.push_back(preorder[i]);
            i += 2;

            while(candidate.size() >= 3
                  && candidate[candidate.size() - 1] == '#'
                  && candidate[candidate.size() - 2] == '#'
                  && candidate[candidate.size() - 3] != '#') {
                candidate.pop_back();
                candidate.pop_back();
                candidate.pop_back();
                candidate.push_back('#');
            }
        }

        return (candidate.size() == 1 && candidate[0] == '#');
    }

    bool isValidSerialization1(string preorder) {
        int n = preorder.length();
        int i = 0;
        int m = 1;

        while (i < n && m > 0)
        {
            while (i < n && preorder[i] != ',')
            {
                i++;
            }

            if (preorder[i-1] == '#')
            {
                m--;
            }
            else
            {
                m++;
            }
            if (i < n)
            {
                i++;
            }
        }

        if (i != n || m != 0)
        {
            return false;
        }
        return true;
    }
};

int main() {
    cout << "Hello world" << endl;

    string s = "9,#, 92,#,#";
    Solution* ss = new Solution;
    cout << ss->isValidSerialization(s) << endl;

    return 0;
}
