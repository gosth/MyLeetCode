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
  int GetTreeDepth(TreeNode* node) {
    if (!node) {
      return 0;
    }
    return std::max(GetTreeDepth(node->left), GetTreeDepth(node->right)) + 1;
  }

  bool isBalanced(TreeNode* root) {
    if (!root) {
      return true;
    }
    return isBalanced(root->left) && isBalanced(root->right) &&
           std::abs(GetTreeDepth(root->left) - GetTreeDepth(root->right)) <= 1;
  }
};