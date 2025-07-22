#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        auto splittedStrView = s | ::std::views::split(' ');
        auto splittedStrViewSize =
            ::std::size_t(::std::ranges::distance(splittedStrView));

        auto p2w = ::std::unordered_map<char, ::std::string>();
        auto w2p = ::std::unordered_map<::std::string, char>();

        if (pattern.size() != splittedStrViewSize) {
            return false;
        }

        for (const auto& [ch, wordSubrange] :
             ::std::views::zip(pattern, splittedStrView)) {
            auto word = std::string(wordSubrange.begin(), wordSubrange.end());
            if ((p2w.contains(ch) && p2w[ch] != word) ||
                (w2p.contains(word) && w2p[word] != ch)) {
                return false;
            }
            p2w[ch] = word;
            w2p[word] = ch;
        }

        return true;
    }
};