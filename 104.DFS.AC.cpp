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
    void DFS(TreeNode* node, int depth, int* max) {
        if (!node) {
            *max = *max > depth ? *max : depth;
            return;
        }
        if (node) {
            ++depth;
            DFS(node->left, depth, max);
            DFS(node->right, depth, max);
        }
    }

    int maxDepth(TreeNode* root) {
        int max = 0;
        DFS(root, 0, &max);
        return max;
    }
};