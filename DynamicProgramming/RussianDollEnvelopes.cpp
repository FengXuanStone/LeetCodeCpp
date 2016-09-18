//
// Created by fengxuan on 2016/9/17.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.empty()) return 0;

        sort(envelopes.begin(), envelopes.end());
        int result = 0;
        auto size = envelopes.size();
        vector<int> dp(size, 1);

        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < i; ++j) {
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        return result;
    }

    int maxEnvelopes1(vector<pair<int, int>>& envelopes) {
        if(envelopes.empty()) return 0;

        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if(a.first == b.first) return a.second > b.second;
            else return a.first < b.first;
        });

        auto size = envelopes.size();
        vector<int> dp;

        for(int i = 0; i < size; ++i) {
            int left = 0, right = dp.size(), t = envelopes[i].second;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if(dp[mid] < t) left = mid + 1;
                else right = mid;
            }

            if(right >= dp.size()) dp.push_back(t);
            else dp[right] = t;
        }

        return dp.size();
    }

    int maxEnvelopes2(vector<pair<int, int>>& envelopes) {
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        for (int i = 0; i < envelopes.size(); ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if (it == dp.end()) dp.push_back(envelopes[i].second);
            else *it = envelopes[i].second;
        }

        return dp.size();
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<pair<int, int>> vec;
    vec.push_back(make_pair(30,50));
    vec.push_back(make_pair(12,2));
    vec.push_back(make_pair(3,4));
    //vec.push_back(make_pair(6,7));
    vec.push_back(make_pair(12,15));
    Solution* ss = new Solution;
    cout << ss->maxEnvelopes(vec) << endl;

    return 0;
}
