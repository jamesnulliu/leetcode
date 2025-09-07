#include "./pch.hpp"

class Solution
{
public:
    int minMutation(const string& startGene, const string& endGene,
                    vector<string>& bank)
    {
        if (bank.empty()) {
            return -1;
        }
        int bankSize = bank.size();
        int src = 0;
        int dst = 0;
        bool hasStart = false;
        bool hasEnd = false;
        for (int i = 0; i < bankSize; ++i) {
            if (startGene == bank[i]) {
                src = i;
                hasStart = true;
            } else if (endGene == bank[i]) {
                dst = i;
                hasEnd = true;
            }
        }
        if (!hasStart) {
            bank.push_back(startGene);
            src = bankSize;
            bankSize += 1;
        }
        if (!hasEnd) {
            bank.push_back(endGene);
            dst = bankSize;
            bankSize += 1;
        }

        this->buildGraph(bank);

        auto bfs = [&]() -> int {
            auto q = queue<int>();
            auto visited = vector<bool>(bankSize, false);
            auto distance = vector<int>(bankSize, 0);
            q.push(src);
            visited[src] = true;
            for (; !q.empty();) {
                int fnt = q.front();
                q.pop();
                if (fnt == dst) {
                    return distance[fnt];
                }
                for (int v : this->adjMat[fnt]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                        distance[v] = distance[fnt] + 1;
                    }
                }
            }

            return -1;
        };

        return bfs();
    }

private:
    void buildGraph(vector<string>& bank)
    {
        // 0 -> bank[0]; 1 -> bank[1]; ...
        int bankSize = bank.size();
        this->adjMat.resize(bankSize);
        for (int i = 0; i < bankSize; ++i) {
            for (int j = i + 1; j < bankSize; ++j) {
                if (Solution::getNumMutations(bank[i], bank[j]) != 1) {
                    continue;
                }
                adjMat[i].push_back(j);
                adjMat[j].push_back(i);
            }
        }
    }

    [[nodiscard]] static int getNumMutations(const string& str1,
                                             const string& str2)
    {
        int n = 0;
        int strlen = str1.size();
        for (int i = 0; i < strlen; ++i) {
            if (str1[i] != str2[i]) {
                n += 1;
            }
        }
        return n;
    }

    vector<vector<int>> adjMat;
};