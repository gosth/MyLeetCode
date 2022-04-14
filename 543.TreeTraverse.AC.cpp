class Solution {
 public:
  void GetSingleSubtreeLongestLevel(TreeNode* node, int* temp_depth, int* depth) {
    if (!node) {
      *depth = *depth < *temp_depth ? *temp_depth : *depth;
      return;
    }
    *temp_depth += 1;
    GetSingleSubtreeLongestLevel(node->left, temp_depth, depth);
    GetSingleSubtreeLongestLevel(node->right, temp_depth, depth);
    *temp_depth -= 1;
  }

  void GetRootNodeBasedLongestDiameter(TreeNode* node, int* step) {
    if (!node) {
      return;
    }
    int current_step = 0;
    if (node->left) {
      int temp_depth = 0, depth = 0;
      GetSingleSubtreeLongestLevel(node->left, &temp_depth, &depth);
      current_step += depth;
    }
    if (node->right) {
      int temp_depth = 0, depth = 0;
      GetSingleSubtreeLongestLevel(node->right, &temp_depth, &depth);
      current_step += depth;
    }
    if (current_step > *step) {
      *step = current_step;
    }
    GetRootNodeBasedLongestDiameter(node->left, step);
    GetRootNodeBasedLongestDiameter(node->right, step);
  }

  int diameterOfBinaryTree(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int step = 0;
    GetRootNodeBasedLongestDiameter(root, &step);
    return step;
  }
};