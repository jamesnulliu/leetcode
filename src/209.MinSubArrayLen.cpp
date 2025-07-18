#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        if (nums.size() == 0) {
            return 0;
        }

        auto minLen = std::numeric_limits<std::size_t>::max();
        auto sum = int32_t(0);
        auto left = nums.begin();
        auto right = nums.begin();

        for (; right < nums.end(); ++right) {
            sum += *right;
            while (sum >= target) {
                minLen = ::std::min(
                    minLen, ::std::size_t(::std::distance(left, right) + 1));
                sum -= *right;
                ++right;
            }
            ++left;
        }

        return minLen == std::numeric_limits<std::size_t>::max() ? 0 : minLen;
    }
};