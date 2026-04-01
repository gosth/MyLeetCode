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

    void buildTree(std::deque<TreeNode*>* queue, std::vector<std::vector<int>>* result) {
        while (true && !queue->empty()) {
            std::size_t queueSize = queue->size();
            std::vector<int> tempResult;
            for (size_t index = 0; index < queueSize; ++index) {
                auto& node = queue->front();
                tempResult.emplace_back(node->val);
                if (node->left) {
                    queue->emplace_back(node->left);
                }
                if (node->right) {
                    queue->emplace_back(node->right);
                }
                queue->pop_front();
            }
            result->emplace_back(tempResult);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return vector<vector<int>>();
        }
        vector<vector<int>> result;
        std::deque<TreeNode*> queue;
        queue.emplace_back(root);
        buildTree(&queue, &result);
        return result;
    }
};