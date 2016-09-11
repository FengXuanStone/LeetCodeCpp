//
// Created by fengxuan on 2016/9/9.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> num(3, 0);
        vector<int> candidate{2,3,5};
        vector<int> result;
        result.push_back(1);
        --n;

        while (n) {
            int minValue = INT_MAX;
            int minIndex = INT_MAX;

            for(int i =0; i < 3; ++i) {
                int tmp = result[num[i]]  * candidate[i];

                if(tmp < minValue) {
                    minValue = tmp;
                    minIndex = i;
                } else if(tmp == minValue)
                    num[i]++;
            }

            result.push_back(minValue);
            num[minIndex]++;
            --n;
        }

        return result.back();
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    cout << ss->nthUglyNumber(10) << endl;

    return 0;
}
