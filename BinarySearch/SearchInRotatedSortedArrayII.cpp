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
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;

        int n = nums.size();
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else if(nums[mid] == nums[right]) {
                left = MinInOrder(nums, left, right);
                break;
            }
            else right = mid;
        }

        int sec = left;
        left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int readMid = (mid + sec) % n;
            if(nums[readMid] == nums[right]) return MinSearch(nums, left, right, target) || MinSearch(nums, 0, sec, target);
            if(nums[readMid] == target) return true;
            else if(nums[readMid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }

    bool MinSearch(vector<int> &nums, int index1, int index2, int target) {
        for(int i = index1; i <= index2; ++i) {
            if(nums[i] == target) return true;
        }
        return false;
    }

    int MinInOrder(vector<int> &nums, int index1, int index2) {
        int result = nums[index1];
        int index = index1;

        for(int i = index1 + 1; i <=  index2; ++i) {
            if(nums[i] < result) {
                result = nums[i];
                index = i;
            }
        }

        return index;
    }

    bool search1(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l)/2;
            if (nums[m] == target) return true; //return m in Search in Rotated Array I
            if (nums[l] < nums[m]) { //left half is sorted
                if (nums[l] <= target && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else if (nums[l] > nums[m]) { //right half is sorted
                if (nums[m] < target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            } else l++;
        }
        return false;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> vec{3,0,0,1,2,2};
    Solution* ss = new Solution;
    cout << ss->search(vec, 3) << endl;

    return 0;
}
