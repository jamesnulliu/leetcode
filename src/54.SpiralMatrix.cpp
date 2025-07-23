#include "./pch.hpp"

/**
 * [NOTE] Not pass yet.
 */

using namespace std;

class Solution
{
public:
    using MatT = ::std::vector<::std::vector<int>>;

    class CoordT
    {
    public:
        int row = 0;
        int col = 0;
    };

    void spiralOneLayer(const MatT& mat, const CoordT& start, int len,
                        ::std::vector<int>& result)
    {
        auto pos = start;
        auto go = [&](int dir, CoordT& pos) -> void {
            switch (dir) {
            case 0: {  // Right
                pos.col += 1;
                break;
            }
            case 1: {  // Down
                pos.row += 1;
                break;
            }
            case 2: {  // Left
                pos.col -= 1;
                break;
            }
            case 3: {  // Up
                pos.row -= 1;
                break;
            }
            }
        };

        for (int direction = 0; direction < 4; ++direction) {
            for (int i = 0; i < len; ++i) {
                result.push_back(mat[pos.row][pos.col]);
                go(direction, pos);
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        auto result = ::std::vector<int>();
        auto start = CoordT{.row = 0, .col = 0};
        auto len = int(matrix.size() - 1);
        auto nloop = int(matrix.size() + 1 / 2);
        for (int i = 0; i < nloop; ++i) {
            spiralOneLayer(matrix, start, len, result);
            start.row += 1;
            start.col += 1;
            len -= 1;
        }
        return result;
    }
};