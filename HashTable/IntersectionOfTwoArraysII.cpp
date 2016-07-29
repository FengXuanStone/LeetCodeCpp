//
// Created by fengxuan on 2016/7/28.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        //intersect
        vector<int> result;

        for(int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if(nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
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

    return 0;
}
