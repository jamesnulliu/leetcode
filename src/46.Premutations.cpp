#include "./pch.hpp"

class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        dfs(nums, 1);
        return this->result;
    }

private:
    void dfs(vector<int>& nums, int cnt)
    {
        if (cnt == int(nums.size())) {
            this->result.push_back(nums);
        }

        for (int i = cnt; i < int(nums.size()); ++i) {
            swap(nums[cnt], nums[i]);

            dfs(nums, cnt + 1);

            swap(nums[cnt], nums[i]);
        }
    }

    vector<vector<int>> result;
};