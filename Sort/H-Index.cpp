//
// Created by fengxuan on 2016/9/2.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;



class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](int a, int b){ return a > b; });

        for(int i = 0; i < citations.size(); ++i) {
            if(i >= citations[i]) return i;
        }

        return citations.size();
    }

    int hIndex1(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](int a, int b){ return a > b; });

        int left = 0, right = citations.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if(citations[mid] > mid) left = mid + 1;
            else right = mid;
        }

        return left;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> vec{0,1};
    Solution* ss = new Solution;
    cout << ss->hIndex1(vec) << endl;

    return 0;
}
