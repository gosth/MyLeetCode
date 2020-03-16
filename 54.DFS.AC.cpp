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
    int kthLargest(TreeNode* root, int k) {
        int result = 0;
        findKthLargest(root, &k, &result);
        return result;
    }

    void findKthLargest(TreeNode* current, int* k, int* result) {
        if (!current) {
            return;
        }
        findKthLargest(current->right, k, result);
        --(*k);
        if (*k == 0) {
            *result = current->val;
            return;
        } else if (*k < 0) {
            return;
        }
        findKthLargest(current->left, k, result);
    }
};