//
// Created by fengxuan on 2016/7/29.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;

        int min = prices[0];
        int result = 0;

        for(int i = 0; i < prices.size(); ++i) {
            if(prices[i] <= min)
                min = prices[i];
            else if(prices[i] - min > result)
                result = prices[i] - min;
        }

        return result;
    }
};


int main() {
    cout << "Hello world" << endl;

    vector<int> vec{7,1,5,3,4,6};

    Solution* ss = new Solution;
    cout << ss->maxProfit(vec) << endl;

    return 0;
}
