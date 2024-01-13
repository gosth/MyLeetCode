#include <vector>
#include <iostream>
#include <deque>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::deque<TreeNode*> queue;
        std::vector<int> results;
        queue.emplace_back(root);
        while (!queue.empty()) {
            const auto level_size = queue.size();
            int level_max_value = INT_MIN;
            for (int index = 0; index < level_size; ++index) {
                const auto current_node = queue.front();
                queue.pop_front();
                level_max_value = std::max(level_max_value, current_node->val);
                if (current_node->left) {
                    queue.emplace_back(current_node->left);
                }
                if (current_node->right) {
                    queue.emplace_back(current_node->right);
                }
            }
            results.emplace_back(level_max_value);
        }
        return results;
    }
};