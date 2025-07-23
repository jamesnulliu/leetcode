#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    using MatT = ::std::vector<::std::vector<int>>;

    void flipVertical(MatT& mat)
    {
        for (int col = 0; col < int(mat.size() / 2); ++col) {
            for (int row = 0; row < int(mat.size()); ++row) {
                std::swap(mat[row][col], mat[row][mat.size() - col - 1]);
            }
        }
    }

    void flipTL2BR(MatT& mat)
    {
        for (int row = 0; row < int(mat.size()); ++row) {
            for (int col = 0; col < int(mat.size()) - row; ++col) {
                ::std::swap(mat[row][col],
                            mat[mat.size() - row][mat.size() - col]);
            }
        }
    }

    void rotate(vector<vector<int>>& matrix)
    {
        flipVertical(matrix);
        flipTL2BR(matrix);
    }
};