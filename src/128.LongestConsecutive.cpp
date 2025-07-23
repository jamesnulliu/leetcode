#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        auto numset = ::std::unordered_set<int>();
        numset.insert_range(nums);

        auto maxLen = ::std::numeric_limits<int>::max();

        for (int x : numset) {
            if (numset.contains(x - 1)) {
                continue;
            }
            int currentX = x;
            int currentLen = 1;
            for (; numset.contains(++currentX);) {
                currentLen += 1;
            }
            maxLen = ::std::max(maxLen, currentLen);
        }

        return maxLen;
    }
};