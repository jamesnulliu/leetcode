#include "./pch.hpp"

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        this->n = n;
        this->k = k;
        auto curComb = vector<int>();
        dfs(1, curComb);
        return this->result;
    }

private:
    void dfs(int cur, vector<int>& curComb)
    {
        if (int(curComb.size()) + this->n - cur + 1 < this->k) {
            return;
        }

        if (int(curComb.size()) == this->k) {
            this->result.push_back(curComb);
            return;
        }

        curComb.push_back(cur);
        dfs(cur + 1, curComb);
        curComb.pop_back();
        dfs(cur + 1, curComb);
    }

    vector<vector<int>> result;
    int k;
    int n;
};