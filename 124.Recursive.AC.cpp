class Solution {
 public:

  int GetNodeSinglePathMaxWeight(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int branch_max_weight = std::max(GetNodeSinglePathMaxWeight(root->left),
                                     GetNodeSinglePathMaxWeight(root->right));
    return std::max(0,
                    std::max(root->val + branch_max_weight,
                             root->val));
  }

  void GetMaxWeight(TreeNode* root, int* max_weight) {
    if (!root) {
      return;
    }
    int left_tree_max_weight = 0, right_tree_max_weight = 0;
    if (root->left) {
      left_tree_max_weight = GetNodeSinglePathMaxWeight(root->left);
    }
    if (root->right) {
      right_tree_max_weight = GetNodeSinglePathMaxWeight(root->right);
    }
    const auto node_max_weight =
        root->val + left_tree_max_weight + right_tree_max_weight;
    *max_weight =
        node_max_weight > *max_weight ? node_max_weight : *max_weight;
    GetMaxWeight(root->left, max_weight);
    GetMaxWeight(root->right, max_weight);
  }

  int maxPathSum(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int max_weight = INT_MIN;
    GetMaxWeight(root, &max_weight);
    return max_weight;
  }
};