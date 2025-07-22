#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) {
            return false;
        }
        auto setS = ::std::unordered_set<char>();
        auto setT = ::std::unordered_set<char>();
        for (const auto& [sch, tch] : ::std::views::zip(s, t)) {
            setS.insert(sch);
            setT.insert(tch);
        }
        return ::std::ranges::all_of(setS, [&](const auto& ch) {
            return setS.count(ch) == setT.count(ch);
        });
    }
};