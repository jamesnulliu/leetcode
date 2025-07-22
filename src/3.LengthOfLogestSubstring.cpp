#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        auto charSet = ::std::unordered_set<char>();
        int length = 0;

        for (auto left = s.begin(), right = s.begin(); right < s.end();
             ++right) {
            auto targetChar = *right;
            for (; left <= right && charSet.contains(targetChar); --left) {
                charSet.erase(charSet.find(*left));
            }
            charSet.insert(targetChar);
            length = ::std::max(length, int(right - left + 1));
        }

        return length;
    }
};