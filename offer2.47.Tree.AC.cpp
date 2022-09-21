class Solution {
 public:
  TreeNode* pruneTree(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    if (!root->val && !root->left && !root->right) {
      return nullptr;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (!root->val && !root->left && !root->right) {
      return nullptr;
    } else {
      return root;
    }
  }
};