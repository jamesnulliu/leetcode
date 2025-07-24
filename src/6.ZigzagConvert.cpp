#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) {
            return s;
        }
        auto result = std::string();
        if (numRows == 2) {
            for (std::size_t i = 0; i < (s.size() + 1) / 2; ++i) {
                result.push_back(s[i * 2]);
            }
            for (std::size_t i = 0; i < s.size() / 2; ++i) {
                result.push_back(s[i * 2 + 1]);
            }
            return result;
        }
        int groupSize = numRows * 2 - 2;
        int nGroup = (s.size() + groupSize - 1) / groupSize;
        for (int row = 0; row < numRows; ++row) {
            for (int groupIdx = 0; groupIdx < nGroup; ++groupIdx) {
                if (row == 0) {
                    result += s[groupIdx * groupSize];
                } else if (row == numRows - 1) {
                    std::size_t targetIdx = row + groupIdx * groupSize;
                    if (targetIdx < s.size()) {
                        result += s[groupIdx * groupSize + row];
                    } else {
                        break;
                    }
                } else {
                    std::size_t targetIdx = row + groupIdx * groupSize;
                    if (targetIdx < s.size()) {
                        result += s[targetIdx];
                    } else {
                        break;
                    }
                    targetIdx = (groupIdx + 1) * groupSize - row;
                    if (targetIdx < s.size()) {
                        result += s[targetIdx];
                    } else {
                        break;
                    }
                }
            }
        }
        return result;
    }
};