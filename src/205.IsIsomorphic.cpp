#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        auto s2t = ::std::unordered_map<char, char>();
        auto t2s = ::std::unordered_map<char, char>();

        for (const auto& [chs, cht] : ::std::views::zip(s, t)) {
            if ((s2t.contains(chs) && s2t[chs] != cht) ||
                (t2s.contains(cht) && t2s[cht] != chs)) {
                return false;
            }
            s2t[chs] = cht;
            t2s[cht] = chs;
        }
        return true;
    }
};