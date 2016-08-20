//
// Created by fengxuan on 2016/8/20.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int i, j;
        int row = board.size();
        if(!row) return;
        int col = board[0].size();

        for(i = 0; i < row; ++i) {
            check(board, i, 0, row, col);
            if(col > 1)
                check(board, i, col - 1, row, col);
        }

        for(j = 0; j < col; ++j) {
            check(board, 0, j, row, col);
            if(row > 1)
                check(board, row - 1, j, row, col);
        }

        for(i = 0; i < row; ++i) {
            for(j = 0; j < col; ++j) {
                board[i][j] = (board[i][j] == '1') ? 'O':'X';
            }
        }
    }

    void check(vector<vector<char>> &vec, int i, int j, int row, int col) {
        if(vec[i][j] == 'O') {
            vec[i][j] = '1';

            if(i > 1) check(vec, i - 1, j, row, col);
            if(j > 1) check(vec, i, j - 1, row, col);
            if(i + 1 < row) check(vec, i + 1, j, row, col);
            if(j + 1 < col) check(vec, i, j + 1, row, col);
        }
    }

    void solve1(vector<vector<char>>& board) {
        int i, j;
        int row = board.size();
        if(!row) return;
        int col = board[0].size();

        for(i = 0; i < row; ++i) {
            if(board[i][0] == 'O')
                check1(board, i, 0, row, col);
            if(col > 1 && board[i][col - 1] == 'O')
                check1(board, i, col - 1, row, col);
        }

        for(j = 0; j < col; ++j) {
            if(board[0][j] == 'O')
                check1(board, 0, j, row, col);
            if(row > 1 && board[row - 1][j] == 'O')
                check1(board, row - 1, j, row, col);
        }

        for(i = 0; i < row; ++i) {
            for(j = 0; j < col; ++j) {
                board[i][j] = (board[i][j] == '1') ? 'O':'X';
            }
        }
    }

    void check1(vector<vector<char>> &vec, int i, int j, int row, int col) {
        typedef pair<int, int> point;
        queue<point> Q;

        Q.push(point(i, j));
        vec[i][j] = '1';

        while (!Q.empty()) {
            point tmp = Q.front();
            Q.pop();

            int x = tmp.first, y = tmp.second;

            if(x > 1 && vec[x - 1][y] == 'O') {
                Q.push(point(x - 1, y));
                vec[x - 1][y] = '1';
            }
            if(y > 1 && vec[x][y - 1] == 'O') {
                Q.push(point(x, y - 1));
                vec[x][y - 1] = '1';
            }
            if(x + 1 < row && vec[x + 1][y] == 'O') {
                Q.push(point(x + 1, y));
                vec[x + 1][y] = '1';
            }
            if(y + 1 < col && vec[x][y + 1] == 'O') {
                Q.push(point(x, y + 1));
                vec[x][y + 1] = '1';
            }
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
