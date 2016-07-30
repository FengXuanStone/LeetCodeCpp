//
// Created by fengxuan on 2016/7/30.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        if(numRows == 0)
            return result;

        result.push_back(vector<int>{1});

        for(int i = 0; i < numRows - 1; ++i) {
            int tmp = 0;
            vector<int> vec;
            vector<int> pre = result[i];
            for(int j = 0; j < pre.size(); ++j) {
                if(j == 0) vec.push_back(1);
                else vec.push_back((pre[j - 1] + pre[j]));
            }
            vec.push_back(1);
            result.push_back(vec);
        }

        return  result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
