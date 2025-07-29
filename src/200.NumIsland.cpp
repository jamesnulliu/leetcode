#include "./pch.hpp"

using namespace std;

class Solution
{
    using MapT = ::std::vector<::std::vector<char>>;

    struct PosT
    {
        int r = 0;  // Row
        int c = 0;  // Col
    };

    bool inRange(MapT& mat, PosT pos)
    {
        int nRows = mat.size();
        int nCols = mat[0].size();

        return (pos.c >= 0 && pos.r >= 0 && pos.r < nRows && pos.c < nCols);
    }

    void dfs(MapT& mat, PosT pos)
    {
        if (!inRange(mat, pos) || mat[pos.r][pos.c] != '1') {
            return;
        }

        mat[pos.r][pos.c] = '0';

        dfs(mat, {.r = pos.r + 1, .c = pos.c});
        dfs(mat, {.r = pos.r - 1, .c = pos.c});
        dfs(mat, {.r = pos.r, .c = pos.c + 1});
        dfs(mat, {.r = pos.r, .c = pos.c - 1});
    }

    void bfs(MapT& mat, PosT pos)
    {
        auto q = ::std::queue<PosT>();
        q.push(pos);
        for (; !q.empty();) {
            auto front = q.front();
            q.pop();
            {
                auto next = PosT(front.r + 1, front.c);
                if (inRange(mat, next) && mat[next.r][next.c] == '1') {
                    mat[next.r][next.c] = '0';
                    q.push(next);
                }
            }
            {
                auto next = PosT(front.r - 1, front.c);
                if (inRange(mat, next) && mat[next.r][next.c] == '1') {
                    mat[next.r][next.c] = '0';
                    q.push(next);
                }
            }
            {
                auto next = PosT(front.r, front.c + 1);
                if (inRange(mat, next) && mat[next.r][next.c] == '1') {
                    mat[next.r][next.c] = '0';
                    q.push(next);
                }
            }
            {
                auto next = PosT(front.r, front.c - 1);
                if (inRange(mat, next) && mat[next.r][next.c] == '1') {
                    mat[next.r][next.c] = '0';
                    q.push(next);
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        int nRows = grid.size();
        int nCols = grid[0].size();

        int nIslands = 0;

        for (int r = 0; r < nRows; ++r) {
            for (int c = 0; c < nCols; ++c) {
                if (grid[r][c] == '1') {
                    nIslands = 1 + nIslands;
                    dfs(grid, {.r = r, .c = c});
                }
            }
        }

        return nIslands;
    }
};