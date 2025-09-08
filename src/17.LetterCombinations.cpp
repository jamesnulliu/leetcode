#include "./pch.hpp"

constexpr bool USE_BACKTRACE_2 = true;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) {
            return {};
        }
        this->n2str = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };

        if constexpr (USE_BACKTRACE_2) {
            auto result = vector<string>();
            auto curComb = string();
            this->backtrace2(digits, 0, result, curComb);
            return result;
        } else {
            return backtrace(digits, 0);
        }
    }

private:
    vector<string> backtrace(const string& digits, int n)
    {
        auto combs = vector<string>();
        if (n == int(digits.size() - 1)) {
            for (char ch : this->n2str[digits[n]]) {
                combs.push_back(to_string(ch));
            }
            return combs;
        }

        auto lastCombs = this->backtrace(digits, n + 1);
        for (char ch : this->n2str[digits[n]]) {
            for (auto& str : lastCombs) {
                combs.push_back(ch + str);
            }
        }
        return combs;
    }

    void backtrace2(const string& digits, int n, vector<string>& allCombs,
                    string& curComb)
    {
        if (n == int(digits.size())) {
            allCombs.push_back(curComb);
            return;
        }
        for (char ch : this->n2str[digits.at(n)]) {
            curComb.push_back(ch);
            this->backtrace2(digits, n + 1, allCombs, curComb);
            curComb.pop_back();
        }
    }

    unordered_map<char, string> n2str;
};