//
// Created by fengxuan on 2016/8/30.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 0) return 0;

        vector<int> indexs(primes.size(), 0);
        vector<int> candidate;
        candidate.push_back(1);

        for(int i = 1; i < n; ++i) {
            int minI = minIndex(indexs, candidate, primes);

            candidate.push_back((candidate[indexs[minI]] * primes[minI]));
            indexs[minI]++;
        }

        return candidate[candidate.size() - 1];
    }

    int minIndex(vector<int> &indexs, vector<int> &candidate, vector<int> &primes) {
        int minIndex = INT_MAX;
        int minValue = INT_MAX;

        for(int i = 0; i < indexs.size(); ++i) {
            int tmp = candidate[indexs[i]] * primes[i];

            if(tmp < minValue) {
                minIndex = i;
                minValue = tmp;
            } else if(tmp == minValue) {
                indexs[i]++;
            }
        }

        return minIndex;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> tt{2,7,13,19};

    Solution* ss = new Solution;
     cout << ss->nthSuperUglyNumber(12, tt) << endl;

    return 0;
}
