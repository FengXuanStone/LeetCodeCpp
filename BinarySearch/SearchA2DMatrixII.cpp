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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();

        if(row <= 0) return false;

        int col = matrix[0].size();
        int left = row - 1, up = 0;

        while (left >= 0 && up < col) {
            int num = matrix[left][up];

            if(num == target) return true;
            else if(num < target) up++;
            else left--;
        }

        return false;
    }
};

int main() {
    cout << "Hello world" << endl;

    strcmp("a","v");

    return 0;
}
