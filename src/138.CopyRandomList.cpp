#include "./pch.hpp"

// Definition for a Node.
class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// ListA -> ListB
auto cachedNodes = unordered_map<Node*, Node*>();

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr) {
            return head;
        }

        if (cachedNodes.contains(head)) {
            return cachedNodes[head];
        }
        auto* newNode = new Node(head->val);
        cachedNodes[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);

        return newNode;
    }
};