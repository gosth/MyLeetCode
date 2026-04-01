/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) {
            return {};
        }
        std::deque<TreeNode *> store;
        store.emplace_back(root);
        std::vector<std::vector<int>> results;
        bool is_positive_direction = true;
        while (!store.empty()) {
            const int store_size = store.size();
            std::vector<int> level_result;
            for (int index = 0; index < store_size;
                 ++index) {
                if (is_positive_direction) {
                    const auto current_item = store.front();
                    if (current_item->left) {
                        store.emplace_back(current_item->left);
                    }
                    if (current_item->right) {
                        store.emplace_back(current_item->right);
                    }
                    level_result.emplace_back(current_item->val);
                    store.pop_front();
                } else {
                    const auto current_item = store.back();
                    if (current_item->right) {
                        store.emplace_front(current_item->right);
                    }
                    if (current_item->left) {
                        store.emplace_front(current_item->left);
                    }
                    level_result.emplace_back(current_item->val);
                    store.pop_back();
                }
            }
            results.emplace_back(level_result);
            is_positive_direction = !is_positive_direction;
        }
        return results;
    }
};