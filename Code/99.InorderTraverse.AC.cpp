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
    TreeNode* first = nullptr, * second = nullptr, * pre = new TreeNode(INT_MIN);

    void inorderTraverse(TreeNode* root) {
        if (!root) {
            return;
        }
        inorderTraverse(root->left);
        if (root->val < pre->val) {
            if (!first) {
                first = pre;
                second = root;
            } else {
                second = root;
            }
        }
        pre = root;
        inorderTraverse(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = nullptr;
        second = nullptr;
        pre->val = INT_MIN;
        inorderTraverse(root);
        if (first && second) {
            int temp = 0;
            temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};