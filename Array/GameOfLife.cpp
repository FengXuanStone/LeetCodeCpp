//
// Created by fengxuan on 2016/8/31.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Solution {
public:
    //00 dead -> dead
    //01 live -> dead
    //10 dead -> live
    //11 live -> live
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) return;

        int row = board.size();
        int col = board[0].size();

        for(int i = 0; i < row; i++) {
            for(int j  = 0; j < col; ++j) {
                int lives = liveNeighbor(board, row, col, i, j);

                if(board[i][j] == 1 && lives >= 2 && lives <= 3)
                    board[i][j] = 3;
                if(board[i][j] == 0 && lives == 3)
                    board[i][j] = 2;
            }
        }

        for(int i = 0; i < row; i++) {
            for(int j  = 0; j < col; ++j) {
                board[i][j] >>= 1;
            }
        }
    }

    int liveNeighbor(vector<vector<int>> &board, int row, int col, int i, int j) {
        int lives = 0;

        for(int x = max(0, i - 1); x <= min(i + 1, row - 1); ++x) {
            for(int y = max(0, j - 1); y <= min(j + 1, col - 1); ++y) {
                lives += (board[x][y] & 1);
            }
        }
        lives -= (board[i][j] & 1);
        return lives;
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<vector<int>> vec{{0}};
    Solution* ss = new Solution;
    ss->gameOfLife(vec);

    return 0;
}
