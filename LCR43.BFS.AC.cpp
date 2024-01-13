class CBTInserter {
public:

    CBTInserter(TreeNode* root) {
        if (!root) {
            return;
        }
        std::deque<TreeNode*> data_queue;
        data_queue.emplace_back(root);
        node_sequence.emplace_back(root);
        while (!data_queue.empty()) {
            const int level_size = data_queue.size();
            for (int index = 0; index < level_size; ++index) {
                auto current_node = data_queue.front();
                if (current_node->left) {
                    data_queue.emplace_back(current_node->left);
                    node_sequence.emplace_back(current_node->left);
                }
                if (current_node->right) {
                    data_queue.emplace_back(current_node->right);
                    node_sequence.emplace_back(current_node->right);
                }
                data_queue.pop_front();
            }
        }
    }

    int insert(int v) {
        node_sequence.emplace_back(new TreeNode(v));
        int new_node_index = node_sequence.size() - 1;
        int father_node_index = new_node_index % 2 == 0 ? (new_node_index - 1) / 2 : new_node_index / 2;
        if (new_node_index % 2 == 0) {
            node_sequence[father_node_index]->right = node_sequence.back();
        } else {
            node_sequence[father_node_index]->left = node_sequence.back();
        }
        return node_sequence[father_node_index]->val;
    }

    TreeNode* get_root() {
        return node_sequence.empty() ? nullptr : node_sequence.front();
    }

private:
    std::vector<TreeNode*> node_sequence;
};