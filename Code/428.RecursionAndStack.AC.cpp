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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) {
            return "";
        }
        std::string result = std::to_string(root->val) + "[";
        for (const auto& child : root->children) {
            result += serialize(child) + ",";
        }
        if (result.back() == ',') {
            result.pop_back();
        }
        result += "]";
        return result;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        Node* head = nullptr;
        std::stack<Node*> status;
        std::string value;
        for (const auto& item : data) {
            if ((item >= '0' && item <= '9') || item == '+' || item == '-') {
                value += item;
            } else if (item == '[') {
                status.emplace(new Node(std::stoi(value)));
                value.clear();
                if (!head) {
                    head = status.top();
                }
            } else if (item == ']') {
                const auto& top = status.top();
                status.pop();
                if (!status.empty()) {
                    const auto& father = status.top();
                    father->children.emplace_back(top);
                }
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));