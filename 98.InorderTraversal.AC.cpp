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
    long long lower = LONG_LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (root->val <= lower) {
            return false;
        } else {
            lower = root->val;
        }
        return isValidBST(root->right);
    }
};