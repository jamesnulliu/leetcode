#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int nRows = matrix.size();
        int nCols = matrix[0].size();
        auto mat = [&matrix](int r, int c) -> int& { return matrix[r][c]; };

        bool row0Is0 = false;
        bool col0Is0 = false;

        for (int col = 0; col < nCols; ++col) {
            if (mat(0, col) == 0) {
                row0Is0 = true;
                break;
            }
        }

        for (int row = 0; row < nRows; ++row) {
            if (mat(row, 0) == 0) {
                col0Is0 = true;
                break;
            }
        }

        for (int row = 1; row < nRows; ++row) {
            for (int col = 1; col < nCols; ++col) {
                if (mat(row, col) == 0) {
                    mat(0, col) = 0;
                    mat(row, 0) = 0;
                }
            }
        }

        for (int row = 1; row < nRows; ++row) {
            for (int col = 1; col < nCols; ++col) {
                if (mat(0, col) == 0 || mat(row, 0) == 0) {
                    mat(row, col) = 0;
                }
            }
        }

        if (row0Is0) {
            for (int col = 0; col < nCols; ++col) {
                mat(0, col) = 0;
            }
        }

        if (col0Is0) {
            for (int row = 0; row < nRows; ++row) {
                mat(row, 0) = 0;
            }
        }
    }
};