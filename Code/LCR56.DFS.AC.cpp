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
    bool DFS(TreeNode* node, int k, std::unordered_set<int>* data) {
        if (!node) {
            return false;
        }
        if (node->left) {
            if (DFS(node->left, k, data)) {
                return true;
            }
        }
        int target = k - node->val;
        if(auto iter = data->find(target); iter != data->end()) {
            return true;
        }
        data->emplace(node->val);
        if (node->right) {
            if (DFS(node->right, k, data)) {
                return true;
            }
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        std::unordered_set<int> data;
        return DFS(root, k, &data);
    }
};