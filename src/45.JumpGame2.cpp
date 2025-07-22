#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int curPos = 0;  // Current position
        int nJumps = 0;

        for (; curPos < (int) nums.size() - 1;) {
            int farthest = curPos + 1;
            for (int i = curPos + 1; i < curPos + nums[curPos] + 1; ++i) {
                if (nums[i] > nums[farthest]) {
                    farthest = i;
                }
            }
            curPos = farthest;
            ++nJumps;
        }

        if (curPos == int(nums.size() - 1)) {
            ++nJumps;
        }

        return nJumps;
    }
};