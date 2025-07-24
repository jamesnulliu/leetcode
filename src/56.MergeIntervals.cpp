#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        auto vecLess = [](const auto& lhs, const auto& rhs) -> bool {
            return lhs[0] < rhs[0];
        };
        ::std::ranges::sort(intervals, vecLess);

        auto result = ::std::vector<::std::vector<int>>();
        intervals.push_back({INT_MAX, INT_MAX});
        int nIntervals = intervals.size();

        int leftVal = intervals[0][0];
        int rightVal = intervals[0][1];
        for (int i = 1; i < nIntervals; ++i) {
            if (intervals[i][0] <= rightVal) {
                rightVal = ::std::max(intervals[i][1], rightVal);
            } else {
                result.push_back({leftVal, rightVal});
                leftVal = intervals[i][0];
                rightVal = intervals[i][1];
            }
        }

        return result;
    }
};