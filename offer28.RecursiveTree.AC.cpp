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
  bool IsSymmetricTree(TreeNode* left_node, TreeNode* right_node) {
    if (!left_node && !right_node) {
      return true;
    }
    if (left_node && right_node) {
      if (left_node->val == right_node->val) {
        return IsSymmetricTree(left_node->left, right_node->right) &&
               IsSymmetricTree(left_node->right, right_node->left);
      }
      return false;
    }
    return false;
  }

  bool isSymmetric(TreeNode* root) {
    if (!root) {
      return true;
    }
    return IsSymmetricTree(root->left, root->right);
  }
};