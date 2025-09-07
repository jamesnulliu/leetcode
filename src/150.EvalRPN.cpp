#include "./pch.hpp"

using namespace std;

constexpr bool isOperator(const string& str)
{
    return str == "+" || str == "-" || str == "*" || str == "/";
}

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        auto stk = stack<string>();
        for (auto& str : tokens) {
            if (!isOperator(str)) {
                stk.push(str);
                continue;
            }
            int rhs = stoi(stk.top());
            stk.pop();
            int lhs = stoi(stk.top());
            stk.pop();
            int result = 0;
            if (str == "+") {
                result = lhs + rhs;
            } else if (str == "-") {
                result = lhs - rhs;
            } else if (str == "*") {
                result = lhs * rhs;
            } else {
                result = lhs / rhs;
            }
            stk.push(to_string(result));
        }
        return stoi(stk.top());
    }
};