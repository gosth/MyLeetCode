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
  int depth(TreeNode* node) {
    if (!node) {
      return 0;
    }
    int left_depth = depth(node->left);
    int right_depth = depth(node->right);
    max_diameter =
        max_diameter < (left_depth + right_depth) ? (left_depth + right_depth) : max_diameter;
    return std::max(left_depth, right_depth) + 1;
  }

  int max_diameter = 0;

  int diameterOfBinaryTree(TreeNode* root) {
    depth(root);
    return max_diameter;
  }
};