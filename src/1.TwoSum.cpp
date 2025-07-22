#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        auto num2idx = ::std::unordered_map<int, int>();
        for (int i = 0; i < int(nums.size()); ++i) {
            auto targetIter = num2idx.find(target - nums[i]);
            if (targetIter != num2idx.end()) {
                return {targetIter->second, i};
            }
            num2idx[nums[i]] = i;
        }
        return {};
    }
};