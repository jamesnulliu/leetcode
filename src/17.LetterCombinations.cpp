class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) {
            return {};
        }
        this->n2str = {
            {'2', "abd"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };

        return backtrace(digits, 0);
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

    unordered_map<char, string> n2str;
};