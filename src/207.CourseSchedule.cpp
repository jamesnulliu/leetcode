#include "./pch.hpp"

constexpr bool USE_BFS = true;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        if constexpr (USE_BFS) {
            return bfs(numCourses, prerequisites);
        } else {
            this->edges.resize(numCourses);
            this->visited.resize(numCourses);
            for (auto& e : prerequisites) {
                edges[e[0]].push_back(e[1]);
            }

            for (int i = 0; i < numCourses; ++i) {
                if (this->visited[i] == VStat::NONE) {
                    dfs(i);
                }
            }

            return this->valid;
        }
    }

private:
    enum class VStat : uint8_t
    {
        NONE = 0,
        VING,
        DONE
    };

    void dfs(int course)
    {
        visited[course] = VStat::VING;

        for (auto& c : edges[course]) {
            if (visited[c] == VStat::NONE) {
                dfs(c);
                if (!this->valid) {
                    return;
                }
            } else if (visited[c] == VStat::VING) {
                this->valid = false;
                return;
            }
        }

        visited[course] = VStat::DONE;
    }

    bool bfs(int numCourses, vector<vector<int>>& prerequisites)
    {
        this->edges.resize(numCourses);
        this->inDeg.resize(numCourses);

        for (const auto& req : prerequisites) {
            this->edges[req[1]].push_back(req[0]);
            this->inDeg[req[0]] += 1;
        }

        queue<int> q;

        for (size_t i = 0; i < inDeg.size(); ++i) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        for (; !q.empty();) {
            int c = q.front();
            q.pop();
            visited += 1;

            for (int n : edges[c]) {
                inDeg[n] -= 1;
                if (inDeg[n] == 0) {
                    q.push(n);
                }
            }
        }

        return visited == numCourses;
    }

    vector<VStat> visited;
    vector<vector<int>> edges;
    vector<int> inDeg;
    bool valid = true;
};