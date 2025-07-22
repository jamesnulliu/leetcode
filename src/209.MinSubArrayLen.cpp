#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        auto minLen = ::std::numeric_limits<::std::size_t>::max();
        int sum = 0;
        for (auto left = nums.begin(), right = nums.begin(); right < nums.end();
             ++right) {
            sum = sum + *right;
            while (sum >= target) {
                minLen = ::std::min(minLen, ::std::size_t(right - left + 1));
                sum = sum - *left;
                ++left;
            }
        }
        return minLen == std::numeric_limits<std::size_t>::max() ? 0 : minLen;
    }
};