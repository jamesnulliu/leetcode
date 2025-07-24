#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    using MatT = ::std::vector<::std::vector<int>>;

    struct PosT
    {
        int row = 0;
        int col = 0;
    };

    [[nodiscard]] int& mat(const PosT& pos)
    {
        return (*m_mat)[pos.row][pos.col];
    }

    [[nodiscard]] auto isInRange(PosT pos) const -> bool
    {
        return pos.row >= 0 && pos.row < nRows && pos.col >= 0 && pos.col < nCols;
    }

    [[nodiscard]] auto wasAlive(PosT pos) -> bool
    {
        switch (mat(pos)) {
        case 0:
        case 2:
            return false;
        case 1:
        case -1:
            return true;
        default:
            return false;
        }
        ::std::abort();
    }

    auto countNeighbors(PosT pos) -> int
    {
        int nNeighbors = 0;
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                auto target =
                    PosT{.row = pos.row - 1 + r, .col = pos.col - 1 + c};
                if (isInRange(target) && wasAlive(target)) {
                    nNeighbors += 1;
                }
            }
        }
        nNeighbors = wasAlive(pos) ? nNeighbors - 1 : nNeighbors;
        return nNeighbors;
    }

    void gameOfLife(vector<vector<int>>& board)
    {
        m_mat = &board;
        nRows = board.size();
        nCols = board[0].size();

        for (int r = 0; r < nRows; ++r) {
            for (int c = 0; c < nCols; ++c) {
                auto pos = PosT{.row = r, .col = c};
                int nNeighbors = countNeighbors(pos);
                if (nNeighbors < 2 && wasAlive(pos)) {
                    mat(pos) = -1;
                } else if (nNeighbors > 3 && wasAlive(pos)) {
                    mat(pos) = -1;
                } else if (nNeighbors == 3 && !wasAlive(pos)) {
                    mat(pos) = 2;
                }
            }
        }

        for (int r = 0; r < nRows; ++r) {
            for (int c = 0; c < nCols; ++c) {
                auto pos = PosT{.row = r, .col = c};
                if (mat(pos) > 0) {
                    mat(pos) = 1;
                } else {
                    mat(pos) = 0;
                }
            }
        }
    }

private:
    MatT* m_mat = nullptr;

    int nRows = 0;
    int nCols = 0;
};