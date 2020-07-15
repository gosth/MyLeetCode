#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (!node) {
            return nullptr;
        }
        const auto iter = mapping.find(node);
        if (iter != mapping.end()) {
            return iter->second;
        }
        const auto& clone = new Node(node->val);
        mapping[node] = clone;
        for (const auto& item : node->neighbors) {
            clone->neighbors.emplace_back(cloneGraph(item));
        }
        return clone;
    }
    std::unordered_map<Node*, Node*> mapping;
};