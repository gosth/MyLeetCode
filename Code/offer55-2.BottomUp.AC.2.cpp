class Solution {
 public:
  int recur(TreeNode* node) {
    if (!node) {
      return 0;
    }
    int left = recur(node->left);
    if (left == -1) {
      return -1;
    }
    int right = recur(node->right);
    if (right == -1) {
      return -1;
    }
    return std::abs(left - right) <= 1 ? std::max(left, right) + 1 : -1;
  }

  bool isBalanced(TreeNode* root) {
    if (!root) {
      return true;
    }
    return recur(root) != -1;
  }
};