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
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        int pathValue = 0;
        preOrder(root, &pathValue, sum, &path, &result);
        return result;
    }

private:
    void
    preOrder(TreeNode* node, int* pathValue, const int sum, std::vector<int>* path, std::vector<std::vector<int>>* result) {
        if (!node) {
            return;
        }
        *pathValue += node->val;
        path->emplace_back(node->val);
        if (!node->left && !node->right && sum == *pathValue) {
            result->emplace_back(*path);
        }
        preOrder(node->left, pathValue, sum, path, result);
        preOrder(node->right, pathValue, sum, path, result);
        *pathValue -= node->val;
        path->pop_back();
    }
};