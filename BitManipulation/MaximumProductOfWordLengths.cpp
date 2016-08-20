//
// Created by fengxuan on 2016/8/6.
//
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        if(size <= 1) return 0;
        int tag[size];
        memset(tag, 0, sizeof(tag));

        for(int i = 0; i < size; ++i) { ;
            for(int j = 0; j < words[i].size(); ++j) {
                tag[i] |= (1 << (words[i][j] - 'a'));
            };
        }

        int maxValue = 0;
        for(int i = 0; i < size; ++i) {
            for(int j = i + 1; j < size; ++j) {
                if((tag[i] & tag[j]) == 0) {
                    int a = words[i].size() * words[j].size();
                    maxValue = maxValue > a ? maxValue : a;
                }
            }
        }

        return maxValue;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<string> str = {"abcw","baz","foo","bar","xtfn","abcdef"};
    Solution* ss = new Solution;
    cout << ss->maxProduct(str) << endl;

    return 0;
}
