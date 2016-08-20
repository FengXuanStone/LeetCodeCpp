//
// Created by fengxuan on 2016/8/7.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        generate(n, n, "", result);

        return result;
    }

    void generate(int left, int right, string s, vector<string> & result) {
        if(left == 0 && right == 0) {
            result.push_back(s);
        }

        if(left > 0) {
            string tmpS = s;
            tmpS += "(";
            int tmp = left;
            generate(--tmp, right, tmpS, result);
        }
        if(right > 0 && left < right) {
            string tmpS = s;
            tmpS += ")";
            int tmp = right;
            generate(left, --tmp, tmpS, result);
        }
    }

    vector<string> generateParenthesis1(int n) {
        vector<string> result;


    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
