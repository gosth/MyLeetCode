class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string result;
        preOrder(root, &result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        int val = 0;
        std::vector<TreeNode*> nodes;
        for (const auto& item : data) {
            if (item == '#') {
                nodes.emplace_back(new TreeNode(val));
                val = 0;
            } else {
                val = val * 10 + item - '0';
            }
        }
        for (size_t i = 1; i < nodes.size(); ++i) {
            insertBst(nodes.front(), nodes[i]);
        }
        return nodes.front();
    }

private:
    void preOrder(const TreeNode* node, std::string* result) {
        if (node) {
            const auto& value = std::to_string(node->val);
            *result += value + "#";
            preOrder(node->left, result);
            preOrder(node->right, result);
        }
    }

    void insertBst(TreeNode* node, TreeNode* insertNode) {
        if (!node || !insertNode) {
            return;
        }
        if (insertNode->val < node->val) {
            if (!node->left) {
                node->left = insertNode;
            } else {
                insertBst(node->left, insertNode);
            }
        } else {
            if (!node->right) {
                node->right = insertNode;
            } else {
                insertBst(node->right, insertNode);
            }
        }
    }
};