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
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) return n;


        for(auto i = nums.begin() + 2; i != nums.end();) {
            if((*i) == *(i - 2)) {
                nums.erase(i - 2);
            } else {
                ++i;
            }
        }

        return nums.size();
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> vec = {1,1,1,2};
    Solution* ss = new Solution;
    ss->removeDuplicates(vec);

    for(int i = 0; i< vec.size(); ++i) {
        cout << vec[i] <<' ';
    }

    cout << endl;

    return 0;
}
