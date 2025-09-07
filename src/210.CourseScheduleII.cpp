#include "./pch.hpp"

constexpr bool USE_BFS=true;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        if constexpr (USE_BFS){
            return this->bfs(numCourses, prerequisites);
        } else {
        for (auto& req : prerequisites) {
            edges[req[1]].push_back(req[0]);
        }

        for (int c = 0; c < numCourses; ++c) {
            if (this->visited[c] == Vstat::NONE) {
                this->dfs(c);
            }
        }

        if (!this->valid) {
            return {};
        }

        auto result = vector<int>();
        for (; !this->courses.empty();) {
            result.push_back(this->courses.top());
            this->courses.pop();
        }

        return result;
    }
    }

private:
    enum class Vstat : int8_t
    {
        NONE = 0,
        ING = 1,
        DONE = 2
    };

    void dfs(int c)
    {
        this->visited[c] = Vstat::ING;
        for (auto& t : this->edges[c]) {
            if (visited[t] == Vstat::NONE) {
                this->dfs(t);
                if (!this->valid) {
                    return;
                }
            } else if (visited[t] == Vstat::ING) {
                this->valid = false;
                return;
            }
        }
        this->courses.push(c);
        this->visited[c] = Vstat::DONE;
    }

    vector<int> bfs(int numCourses, vector<vector<int>>& prerequisites)
    {
        inDegs.resize(numCourses);

        for (const auto& req : prerequisites) {
            edges[req[1]].push_back(req[0]);
            inDegs[req[0]] += 1;
        }

        auto q = queue<int>();
        for (int i = 0; i < numCourses; ++i) {
            if (inDegs[i] == 0) {
                q.push(i);
            }
        }

        auto result = vector<int>();
        for (; !q.empty();) {
            int front = q.front();
            q.pop();
            result.push_back(front);
            for(int adjC : edges[front]){
                inDegs[adjC] -= 1;
                if (inDegs[adjC] == 0){
                    q.push(adjC);
                }
            }
        }

        if (result.size() != size_t(numCourses)) {
            return {};
        }
        return result;
    }

    vector<vector<int>> edges;
    vector<Vstat> visited;
    vector<int> inDegs;
    stack<int> courses;
    bool valid = true;
};
