//
// Created by fengxuan on 2016/9/12.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int count(int n) {
        vector<char> candidate;
        return count(candidate, 0, n);
    }

    int count(vector<char> &candidate, int k, int n) {
        if(k == n) return 1;

        int result = 0;

        if(k < 2) {
            for(int i = 0; i < 3; ++i) {
                candidate.push_back((char)('A' + i));
                result += count(candidate, k + 1, n);
                candidate.erase(candidate.end() - 1);
            }
        } else {
            char a = candidate.back();
            char b = candidate[candidate.size() - 2];

            if(a == b) {
                for(int i = 0; i < 3; ++i) {
                    candidate.push_back((char)('A' + i));
                    result += count(candidate, k + 1, n);
                    candidate.erase(candidate.end() - 1);
                }
            } else {
                candidate.push_back(a);
                result += count(candidate, k + 1, n);
                candidate.erase(candidate.end() - 1);
                candidate.push_back(b);
                result += count(candidate, k + 1, n);
                candidate.erase(candidate.end() - 1);
            }
        }

        return result;
    }
};



int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->count(6) << endl;

    return 0;
}
