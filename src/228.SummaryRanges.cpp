#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        int nNums = nums.size();
        if (nNums == 0) {
            return {};
        }
        if (nNums == 1) {
            return {std::to_string(nums[0])};
        }

        auto result = ::std::vector<::std::string>();

        int firstVal = nums[0];
        int lastVal = nums[0];
        for (int i = 1; i < nNums; ++i) {
            if (nums[i] != lastVal + 1) {
                if (firstVal != lastVal) {
                    result.push_back(::std::to_string(firstVal) + "->" +
                                     ::std::to_string(lastVal));
                } else {
                    result.push_back(::std::to_string(firstVal));
                }
                firstVal = nums[i];
                lastVal = nums[i];
                if (i == nNums - 1) {
                    result.push_back(::std::to_string(firstVal));
                    break;
                }
                continue;
            }
            lastVal = nums[i];
            if (i == nNums - 1) {
                result.push_back(::std::to_string(firstVal) + "->" +
                                 ::std::to_string(lastVal));
            }
        }

        return result;
    }
};