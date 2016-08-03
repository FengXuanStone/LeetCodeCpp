//
// Created by fengxuan on 2016/8/3.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        vector<int> candidate;
        bool flag = true;
        long long result = x;

        if(x < 0) {
            flag = false;
            result = 0l - (long long)x;
        }

        while (result != 0) {
            candidate.push_back(result % 10);
            result = result/ 10;
        }

        result = 0;
        for(int i = 0; i < candidate.size(); ++i) {
            result = result * 10 + candidate[i];
        }

        if(result > INT32_MAX) return 0;
        else if(!flag) result = 0 - result;

        return (int)result;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution * ss = new Solution;
    ss->reverse(-2147483648);

    return 0;
}
