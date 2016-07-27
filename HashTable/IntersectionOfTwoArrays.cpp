//
// Created by fengxuan on 2016/7/27.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        //intersect
        vector<int> result;

        for(int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if(nums1[i] == nums2[j]) {
                if (result.empty() || result.back() != nums1[i]) result.push_back(nums1[i]);
                ++i;
                ++j;
            } else if(nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }
        return  result;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> s1 = {1, 2, 2, 1};
    vector<int> s2 = {2, 2};

    auto ss = new Solution;
    auto result = ss->intersection(s1,s2);

    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
     cout << endl;

    return 0;
}
