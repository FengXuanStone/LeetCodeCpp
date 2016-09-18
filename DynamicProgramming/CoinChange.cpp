//
// Created by fengxuan on 2016/9/17.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty())
            return -1;
        if(0 == amount) return 0;

        vector<int> candidate;
        candidate.push_back(0);
        int size = coins.size();

        for(int i = 1; i <= amount; ++i) {
            int minNum = INT32_MAX;
            for(int j = 0; j < size; ++j) {
                int s = i - coins[j];

                if(0 == s) {
                    minNum = 1;
                    break;
                } else if(s < 0) {
                    continue;
                } else {
                    if(candidate[s] != 0) minNum = min(minNum, candidate[s] + 1);
                }
            }

            if(INT32_MAX == minNum) candidate.push_back(0);
            else candidate.push_back(minNum);
        }

        if(candidate.back() == 0) return -1;
        else return candidate.back();
    }


    int coinChange1(vector<int>& coins, int amount) {
        if(coins.empty() || amount < 0) return -1;
        if(0 == amount) return 0;

        sort(coins.begin(), coins.end());
        int i = 0;
        for(; i < coins.size() && coins[i] <= amount; ++i) { }

        int cnt = 0;
        int minCoins = amount + 1;

        DFS(coins, i-1, amount, cnt, minCoins);

        return minCoins > amount ? -1 : minCoins;
    }

    void DFS(vector<int> &coins, int index, int &amount, int &cnt, int &minCoins) {
        if(index == -1) return;

        int max = amount / coins[index];
        for(int i = max; i >= 0; i--)
        {
            amount -= i*coins[index];
            cnt += i;
            if(amount > 0 && cnt < minCoins )
            {
                DFS(coins, index-1, amount, cnt, minCoins);
            }
            else if(amount == 0 )
            {
                minCoins = min(minCoins, cnt);
            }
            else
            {
                amount += i*coins[index];
                cnt -= i;

                break;
            }

            amount += i*coins[index];
            cnt -= i;
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
