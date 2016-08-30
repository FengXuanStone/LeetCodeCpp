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
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX, secMin = INT_MAX;

        for(int i : nums) {
            if(i <= min) min = i;
            else if(i < secMin) secMin = i;
            else if(i > secMin) return true;
        }

        return false;
    }
};

int main() {
    cout << "Hello world" << endl;

    strcmp("a","v");

    return 0;
}
