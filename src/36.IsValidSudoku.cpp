#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        using ArrT = std::array<int, 9>;
        auto rowsHash = ::std::array<ArrT, 9>();
        auto colsHash = ::std::array<ArrT, 9>();
        auto blocksHash = ::std::array<ArrT, 9>();

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                auto bkey = int(board[r][c] - '1');
                if (rowsHash[r][bkey] != 0 || colsHash[c][bkey] != 0 ||
                    blocksHash[r / 3 * 3 + c / 3][bkey] != 0) {
                    return false;
                }
                rowsHash[r][bkey] = 1;
                colsHash[c][bkey] = 1;
                blocksHash[r / 3 * 3 + c / 3][bkey] = 1;
            }
        }

        return true;
    }
};