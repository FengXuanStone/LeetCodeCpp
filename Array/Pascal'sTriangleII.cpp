//
// Created by fengxuan on 2016/7/30.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        result[rowIndex] = 1;

        for(int i = rowIndex - 1; i >= 0; --i) {
            int tmp = 1;
            for(int j = rowIndex - 1; j >= i; --j) {
                int ss = tmp + result[j];
                tmp = result[j];
                result[j] = ss;
            }
            result[i] = 1;
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    Solution* ss = new Solution;
    ss->getRow(3);

    return 0;
}
