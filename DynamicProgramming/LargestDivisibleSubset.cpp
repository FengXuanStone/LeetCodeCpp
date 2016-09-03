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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        if(n == 0) return result;
        sort(nums.begin(), nums.end());

        vector<int> path(n, -1);
        vector<int> candidate(n, 0);
        candidate[0] = 1;
        int left = nums[0];
        int maxV = 0;
        int maxIndex = 0;

        for(int i = 1; i < n; ++i) {
            int maxj = -1;
            int max = 0;
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0) {
                    if(candidate[j] > max) {
                        max = candidate[j];
                        maxj = j;
                    }
                }
            }
            if(maxj == -1) candidate[i] = 1;
            else {
                candidate[i] = candidate[maxj] + 1;
                path[i] = maxj;
                if(candidate[i] > maxV) {
                    maxV = candidate[i];
                    maxIndex = i;
                }
            }
        }

        while (maxIndex != -1) {
            result.push_back(nums[maxIndex]);
            maxIndex = path[maxIndex];
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> result;
    vector<int> tmp{1,2,4,8,9,72};
    Solution* ss = new Solution;
    result = ss->largestDivisibleSubset(tmp);

    for(int i = 0; i< result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;


    return 0;
}
