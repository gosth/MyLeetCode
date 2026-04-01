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
    void flatten(TreeNode* root) {
        TreeNode* last = 0;
        preOreder(root, last);
    }

private:
    void preOreder(TreeNode* node, TreeNode*& last) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            last = node;
            return;
        }
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        TreeNode* leftLast = nullptr;
        TreeNode* rightLast = nullptr;
        if (left) {
            preOreder(left, leftLast);
            node->left = nullptr;
            node->right = left;
            last = leftLast;
        }
        if (right) {
            preOreder(right, rightLast);
            if (leftLast) {
                leftLast->right = right;
            }
            last = rightLast;
        }
    }
};
