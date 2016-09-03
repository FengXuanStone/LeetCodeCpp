//
// Created by fengxuan on 2016/9/3.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m==n) return m;
        else if (m==0) return 0;

        vector<bool> result;

        for(int i = 0; i < 32; ++i) {
            int t = m >> i;

            if(t == 0) break;

            if(t & 1) {
                int k = n >> i;
                if(k > t) result.push_back(false);
                else result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        int ss = 0;

        for(auto i = result.rbegin(); i != result.rend(); ++i) {
            if((*i)) ss = ss * 2 + 1;
            else ss *= 2;
        }

        return ss;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->rangeBitwiseAnd(5,7) << endl;

    return 0;
}
