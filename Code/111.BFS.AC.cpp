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
    int minDepth(TreeNode* root) {
        int minDepth = 0;
        if (!root) {
            return minDepth;
        }
        std::deque<TreeNode*> queue;
        queue.emplace_back(root);
        while (!queue.empty()) {
            ++minDepth;
            size_t length = queue.size();
            for (int i = 0; i < length; ++i) {
                auto& node = queue.front();
                if (!node->left && !node->right) {
                    return minDepth;
                } else {
                    if (node->left) {
                        queue.emplace_back(node->left);
                    }
                    if (node->right) {
                        queue.emplace_back(node->right);
                    }
                }
                queue.pop_front();
            }
        }
        return minDepth;
    }
};