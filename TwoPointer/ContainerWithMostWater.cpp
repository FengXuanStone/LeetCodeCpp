//
// Created by fengxuan on 2016/9/1.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return 0;

        int left = 0, right = height.size();
        int max = min(height[left], height[right - 1]) * (right - left - 1);

        while (left < right) {
            if(height[left] < height[right - 1]) {
                left++;
                int tmp = min(height[left], height[right - 1]) * (right - left - 1);
                max = max > tmp ? max : tmp;
            } else {
                right--;
                int tmp = min(height[left], height[right - 1]) * (right - left - 1);
                max = max > tmp ? max : tmp;
            }
        }

        return max;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> height{1,2,3,4};
    Solution* ss = new Solution;
    cout << ss->maxArea(height) << endl;

    return 0;
}
