//
// Created by fengxuan on 2016/9/5.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        int row = board.size();

        if(row <= 0) return 0;
        vector<int> result(row, 0);
        result[0] = board[0][0];
        for(int i = 1; i < row; ++i) {
            result[i] = result[i - 1] + board[0][i];
        }

        for(int i = 1; i < row; ++i) {
            result[0] = result[0] + board[i][0];
            for(int j = 1; j < row; ++j) {
                result[j] = max(result[j], result[j - 1]) + board[i][j];
            }
        }

        return result.back();
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
