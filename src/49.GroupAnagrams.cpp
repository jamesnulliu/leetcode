#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        auto hashFn = [](const ::std::array<int, 26>& obj) {
            return ::std::accumulate(
                obj.begin(), obj.end(), 0, [&](auto acc, int num) {
                    return (acc << 1) + ::std::hash<int>{}(num);
                });
        };
        auto map = ::std::unordered_map<::std::array<int, 26>,
                                        ::std::vector<int>, decltype(hashFn)>();

        std::size_t idx = 0;
        for (const auto& str : strs) {
            auto arr = ::std::array<int, 26>();
            ::std::ranges::for_each(str, [&arr](char ch) { ++arr[ch - 'a']; });
            map[arr].push_back(idx++);
        }

        auto result = ::std::vector<::std::vector<::std::string>>();
        for (const auto& [_, val] : map) {
            result.emplace_back();
            ::std::ranges::for_each(val,
                                    [&strs, &vec = result.back()](int idx) {
                                        vec.push_back(strs[idx]);
                                    });
        }
        return result;
    }
};