#include "./pch.hpp"

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node*> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node* dfs(Node* oldNode)
    {
        if (oldNode == nullptr) {
            return oldNode;
        }

        auto newNodeIt = hash.find(oldNode);
        if (newNodeIt != hash.end()) {
            return newNodeIt->second;
        }

        auto* newNode = new Node();
        newNode->val = oldNode->val;
        hash[oldNode] = newNode;

        for (auto* neighbor : oldNode->neighbors) {
            newNode->neighbors.push_back(dfs(neighbor));
        }

        return newNode;
    }

    Node* bfs(Node* oldNode)
    {
        auto q = ::std::queue<Node*>();
        if (oldNode == nullptr) {
            return oldNode;
        }
        auto* newNode = new Node();
        newNode->val = oldNode->val;
        hash[oldNode] = newNode;
        q.push(oldNode);
        for (; !q.empty();) {
            auto* front = q.front();
            q.pop();
            for (auto* neighbor : front->neighbors) {
                if (!hash.contains(neighbor)) {
                    auto* newNeighbor = new Node();
                    newNeighbor->val = neighbor->val;
                    hash[neighbor] = newNeighbor;
                    q.push(neighbor);
                }
                hash[front]->neighbors.push_back(hash[neighbor]);
            }
        }
        return newNode;
    }

    Node* cloneGraph(Node* node)
    {
        return dfs(node);
    }

    ::std::unordered_map<Node*, Node*> hash;
};