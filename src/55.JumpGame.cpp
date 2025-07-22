#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        if (nums.size() < 2) {
            return true;
        }
        int max = nums[0];
        for (int i = 1; i < int(nums.size()); ++i) {
            if (i > max) {
                return false;
            }
            max = ::std::max(nums[i], max);
        }
        return true;
    }
};