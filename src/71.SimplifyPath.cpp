#include "./pch.hpp"

using namespace std;

class Solution
{
public:
    auto splitPath(std::string str) -> std::vector<std::string>
    {
        auto splittedPath = std::vector<std::string>();
        auto path = std::string("/");
        for (std::size_t i = 1; i < str.size(); ++i) {
            if (str[i] == '/') {
                splittedPath.push_back(path);
                path = "/";
                continue;
            }
            path += str[i];
        }
        splittedPath.push_back(path);
        return splittedPath;
    }

    string simplifyPath(string path)
    {
        auto splittedPath = splitPath(std::move(path));
        auto stk = std::deque<std::string>();
        for (auto& p : splittedPath) {
            if (p == "/" || p == "/.") {
                continue;
            }
            if (p == "/..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
                continue;
            }
            stk.push_back(p);
        }
        auto relPath = std::string();
        while (!stk.empty()) {
            relPath += stk.front();
            stk.pop_front();
        }

        relPath = relPath == "" ? "/" : relPath;
        return  relPath;
    }
};