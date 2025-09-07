#include "./pch.hpp"

class LRUCache
{
public:
    struct Node
    {
        int value = 0;
        int key = 0;
        Node* prev = nullptr;
        Node* next = nullptr;
    };

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        auto* dummyHead = new Node();
        auto* dummyTail = new Node();
        dummyTail->prev = dummyHead;
        dummyHead->next = dummyTail;
        this->dHead = dummyHead;
        this->dTail = dummyTail;
    }

    int get(int key)
    {
        auto node = this->key2node.find(key);
        if (node == this->key2node.end()) {
            return -1;
        }
        this->moveNodeToHead(node->second);
        return node->second->value;
    }

    void put(int key, int value)
    {
        auto it = this->key2node.find(key);
        if (it != this->key2node.end()) {
            it->second->value = value;
            moveNodeToHead(it->second);
            return;
        }

        if (this->size == capacity) {
            this->removeTailNode();
            this->size -= 1;
        }

        Node* newNode = new Node();
        newNode->key = key;
        newNode->value = value;
        this->dHead->next->prev = newNode;
        this->dHead->next = newNode;
        this->key2node[key] = newNode;
        this->size += 1;
    }

    void moveNodeToHead(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = this->dHead->next;
        node->prev = this->dHead;
        this->dHead->next->prev = node;
        this->dHead->next = node;
    }

    void removeTailNode()
    {
        if (this->dTail->prev == this->dHead) {
            return;
        }
        auto* targetNode = this->dTail->prev;
        targetNode->prev->next = targetNode->next;
        targetNode->next->prev = targetNode->prev;
        this->key2node.erase(this->key2node.find(targetNode->key));
        delete targetNode;
    }

private:
    unordered_map<int, Node*> key2node;
    Node* dHead;  // Most used
    Node* dTail;  // Least used
    int capacity = 0;
    int size = 0;
};