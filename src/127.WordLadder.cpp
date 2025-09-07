#include "./pch.hpp"

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        this->buildGraph(beginWord, wordList);
        if (!this->w2i.contains(endWord)) {
            return 0;
        }

        auto q = queue<int>();
        auto w2i = [this](auto& str) -> int { return this->w2i[str]; };
        auto distance = vector<int>(this->numNodes, numeric_limits<int>::max());
        auto visited = vector<bool>(this->numNodes, false);

        q.push(w2i(beginWord));
        distance[w2i(beginWord)] = 0;

        for (; !q.empty();) {
            int fnt = q.front();
            q.pop();

            if (fnt == w2i(endWord)) {
                return distance[fnt] / 2 + 1;
            }

            for (int v : this->adjMat[fnt]) {
                if (distance[v] != numeric_limits<int>::max()) {
                    continue;
                }
                q.push(v);
                distance[v] = distance[fnt] + 1;
            }
        }

        return 0;
    }

    void addNode(const string& word)
    {
        if (this->w2i.contains(word)) {
            return;
        }
        this->w2i[word] = this->numNodes;
        this->numNodes += 1;
        this->adjMat.emplace_back();
    }

    void addEdge(string& word)
    {
        this->addNode(word);
        int idx = this->w2i[word];
        for (char& ch : word) {
            char tmp = ch;
            ch = '*';
            this->addNode(word);
            this->adjMat[idx].push_back(this->w2i[word]);
            this->adjMat[this->w2i[word]].push_back(idx);
            ch = tmp;
        }
    }

    void buildGraph(string& start, vector<string>& wordList)
    {
        this->addEdge(start);
        for (auto& word : wordList) {
            if (this->w2i.contains(word)) {
                continue;
            }
            this->addEdge(word);
        }
    }

    unordered_map<string, int> w2i;
    vector<vector<int>> adjMat;
    int numNodes;
};