//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<int> rowNum;
        set<int> colNum;
        set<int> blockNum;

        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                int s1 = board[i][j] == '.' ? 0 :  board[i][j] - '0';
                int s2 = board[j][i] == '.' ? 0 : board[j][i] - '0';

                if(s1 != 0) {
                    if(rowNum.find(s1) == rowNum.end()) rowNum.insert(s1);
                    else return false;
                }
                if(s2 != 0) {
                    if(colNum.find(s2) == colNum.end()) colNum.insert(s2);
                    else return false;
                }

                if(i % 3 == 0 && j % 3 == 0) {
                    for(int k = i; k < i + 3; ++k) {
                        for(int s = j; s < j + 3; ++s) {
                            int s3 = board[k][s] == '.' ? 0 : board[k][s] - '0';

                            if(s3 != 0) {
                                if(blockNum.find(s3) == blockNum.end()) blockNum.insert(s3);
                                else return false;
                            }
                        }
                    }
                }
                blockNum.clear();
            }
            rowNum.clear();
            colNum.clear();
        }

        return true;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
