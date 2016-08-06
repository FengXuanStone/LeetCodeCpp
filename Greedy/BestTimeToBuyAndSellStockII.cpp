//
// Created by fengxuan on 2016/8/6.
//
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int result = 0;
        int tmpRes = 0;
        int minValue = (*prices.cbegin());
        int pre = (*prices.cbegin());

        for(auto i = prices.cbegin() + 1; i != prices.cend(); ++i) {
            int tmp = (*i) - minValue;

            if((*i) > pre) {
                if(tmp > tmpRes) {
                    tmpRes = tmp;
                }
            } else {
                result += tmpRes;
                minValue = (*i);
                tmpRes = 0;
            }

            pre = (*i);
        }

        result += tmpRes;

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> tt{6,1,3,2,4,7};

    Solution * ss = new Solution;
    ss->maxProfit(tt);

    return 0;
}
