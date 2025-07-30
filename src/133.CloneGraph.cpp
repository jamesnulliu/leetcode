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
    Node* dfs(Node* curNode)
    {
        if (curNode == nullptr) {
            return curNode;
        }

        auto newNodeIt = hash.find(curNode);
        if (newNodeIt != hash.end()) {
            return newNodeIt->second;
        }

        auto* newNode = new Node(curNode->val);
        hash[curNode] = newNode;

        for (auto* neighbor : curNode->neighbors) {
            newNode->neighbors.push_back(dfs(neighbor));
        }

        return newNode;
    }

    Node* bfs(Node* curNode)
    {
        if (curNode == nullptr) {
            return curNode;
        }

        auto q = ::std::queue<Node*>();
        q.push(curNode);
        hash[curNode] = new Node(curNode->val);
        for (; !q.empty();) {
            auto* front = q.front();
            q.pop();

            for (auto* neighbor : front->neighbors) {
                if (!hash.contains(neighbor)) {
                    hash[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                hash[front]->neighbors.push_back(hash[neighbor]);
            }
        }

        return hash[curNode];
    }

    Node* cloneGraph(Node* node)
    {
        return dfs(node);
    }

    ::std::unordered_map<Node*, Node*> hash;
};