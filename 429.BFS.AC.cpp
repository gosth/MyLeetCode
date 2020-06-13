/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        std::vector<std::vector<int>> result;
        if (!root) {
            return result;
        }
        std::deque<Node*> q;
        q.emplace_back(root);
        while (!q.empty()) {
            std::vector<int> result2;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto& top = q.front();
                result2.emplace_back(top->val);
                for (const auto& child : top->children) {
                    q.emplace_back(child);
                }
                q.pop_front();
            }
            result.emplace_back(result2);
        }
        return result;
    }
};