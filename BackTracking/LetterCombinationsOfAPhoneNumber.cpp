//
// Created by fengxuan on 2016/9/9.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    map<int, string> candidate = {{0, " "}, {1, ""},
            {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
            {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"},
    };

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string tmp = "";
        int n = digits.size();

        if(n == 0) return result;

        insertLetter(result, tmp, digits, n, 0);
        return result;
    }

    void insertLetter(vector<string> &result, string &tmp, string digits, int n, int i) {
        string str = candidate[(digits[i] - '0')];

        int size = str.size();
        if(size == 0 && i != n - 1) insertLetter(result, tmp, digits, n, i + 1);
        else {
            for(int j = 0; j < size; ++j) {
                tmp += str[j];
                if(i == n - 1) {
                    result.push_back(tmp);
                } else {
                    insertLetter(result, tmp, digits, n, i + 1);
                }
                tmp = tmp.substr(0, tmp.size() - 1);
            }
        }
    }
};

int main() {
    cout << "Hello world" << endl;
    vector<string> result;
    Solution* ss = new Solution;
    result = ss->letterCombinations("");

    for(int j = 0; j < result.size(); ++j) {
        cout << result[j] << ' ';
    }

    cout << endl;

    return 0;
}
