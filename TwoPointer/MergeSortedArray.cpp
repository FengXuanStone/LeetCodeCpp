//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        int lastM = m - 1;
        int lastN = n - 1;

        while (last >= 0 && lastM >= 0 && lastN >= 0)  {
            if(nums1[lastM] > nums2[lastN]) {
                nums1[last] = nums1[lastM];
                --lastM;
            } else {
                nums1[last] = nums2[lastN];
                --lastN;
            }
            --last;
        }

        while (lastN >= 0) {
            nums1[last] = nums2[lastN];
            --last;
            --lastN;
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
