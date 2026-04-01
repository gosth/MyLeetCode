class Solution {
public:
    bool isValid(TreeNode* node, long long lower, long long upper) {
        if (!node) {
            return true;
        }
        if (node->val <= lower || node->val >= upper) {
            return false;
        }
        return isValid(node->left, lower, node->val) && isValid(node->right, node->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isValid(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};