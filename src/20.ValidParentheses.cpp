#include "./pch.hpp"

using namespace std;

class Solution
{

public:
    bool isValid(const string& s)
    {
        int nChs = s.size();
        if (nChs % 2 != 0) {
            return false;
        }

        auto hash = ::std::unordered_map<char, char>{
            {')', '('}, {']', '['}, {'}', '{'}};

        auto stk = ::std::stack<char>();

        for (auto ch : s) {
            if (!hash.contains(ch)) {
                stk.push(ch);
            } else {
                if(stk.empty()) {
                    return false;
                }
                auto top = stk.top();
                stk.pop();
                if (top != hash[ch]) {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};