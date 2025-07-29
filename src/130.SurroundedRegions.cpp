#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    using MatT = ::std::vector<::std::vector<char>>;

    bool inRange(MatT& mat, int r, int c)
    {
        int nRows = mat.size();
        int nCols = mat[0].size();

        return r > -1 && c > -1 && r < nRows && c < nCols;
    }

    void dfs(MatT& mat, int r, int c)
    {
        if (!inRange(mat, r, c) || mat[r][c] != 'O') {
            return;
        }
        mat[r][c] = 'A';
        dfs(mat, r + 1, c);
        dfs(mat, r - 1, c);
        dfs(mat, r, c + 1);
        dfs(mat, r, c - 1);
    }

    void solve(vector<vector<char>>& board)
    {
        int nRows = board.size();
        int nCols = board[0].size();

        for (auto r : {0, nRows - 1}) {
            for (int c = 0; c < nCols; ++c) {
                if (board[r][c] == 'O') {
                    dfs(board, r, c);
                }
            }
        }

        for (auto c : {0, nCols - 1}) {
            for (int r = 0; r < nRows; ++r) {
                if (board[r][c] == 'O') {
                    dfs(board, r, c);
                }
            }
        }

        for (int r = 0; r < nRows; ++r) {
            for (int c = 0; c < nCols; ++c) {
                if (board[r][c] == 'A') {
                    board[r][c] = 'O';
                } else if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
    }
};