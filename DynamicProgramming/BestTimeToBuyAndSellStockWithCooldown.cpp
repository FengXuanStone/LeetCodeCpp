//
// Created by fengxuan on 2016/8/28.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
        for (int price : prices) {
            pre_buy = buy;
            buy = max(pre_sell - price, pre_buy);
            pre_sell = sell;
            sell = max(pre_buy + price, pre_sell);
        }
        return sell;
    }
};

int main() {
    cout << "Hello world" << endl;

    strcmp("a","v");

    return 0;
}
