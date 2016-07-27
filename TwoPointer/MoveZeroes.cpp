//
// Created by fengxuan on 2016/7/27.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        while (nums[zero] != 0 && zero != nums.size()) ++zero;
        if(zero == nums.size()) return;

        for(int notZero = zero; notZero < nums.size(); ++notZero) {
            if(nums[notZero] != 0) {
                nums[zero] = nums[notZero];
                nums[notZero] = 0;
                zero++;
            }
        }
    }

    void moveZeroes1(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};

int main() {
    vector<int> tmp;

    int a;
    while (cin >> a) {
        tmp.push_back(a);
    }

    auto ss = new Solution;
    ss->moveZeroes(tmp);

    for(int i = 0; i < tmp.size(); i++) {
        cout << tmp[i] << ' ';
    }
    cout << endl;

    return 0;
}
