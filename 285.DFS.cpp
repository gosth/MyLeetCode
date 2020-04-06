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
    TreeNode *prev = nullptr;
    TreeNode *next = nullptr;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) {
            return nullptr;
        }
        inorderTraversal(root, p);
        return next;
    }


    void inorderTraversal(TreeNode* root, TreeNode* p) {
        if (root->left) {
            inorderTraversal(root->left, p);
        }
        if (prev && prev == p) {
            next = root;
        }
        prev = root;
        if (root->right) {
            inorderTraversal(root->right, p);
        }
    }
};