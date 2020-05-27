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
    void BFS(std::deque<TreeNode*>* queue, std::vector<vector<int>>* result) {
        bool direction = true;
        while (!queue->empty()) {
            std::vector<int> tempResult;
            if (direction) {
                for (auto& item : *queue) {
                    tempResult.emplace_back(item->val);
                }
            } else {
                for (auto it = queue->rbegin(); it != queue->rend(); ++it) {
                    tempResult.emplace_back((*it)->val);
                }
            }
            result->emplace_back(tempResult);
            direction = !direction;
            size_t size = queue->size();
            for (size_t index = 0; index < size; ++index) {
                auto& node = queue->front();
                if (node->left) {
                    queue->emplace_back(node->left);
                }
                if (node->right) {
                    queue->emplace_back(node->right);
                }
                queue->pop_front();
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        std::deque<TreeNode*> queue;
        queue.emplace_back(root);
        BFS(&queue, &result);
        return result;
    }
};