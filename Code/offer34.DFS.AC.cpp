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
  void DFS(int target,
           TreeNode* node,
           std::vector<std::vector<int>>* result,
           int* temp_sum,
           std::vector<int>* current_path) {
    current_path->emplace_back(node->val);
    *temp_sum += node->val;
    if (!node->left && !node->right) {
      if (*temp_sum == target) {
        result->emplace_back(*current_path);
      }
      return;
    }
    if (node->left) {
      DFS(target, node->left, result, temp_sum, current_path);
      *temp_sum -= node->left->val;
      current_path->pop_back();
    }
    if (node->right) {
      DFS(target, node->right, result, temp_sum, current_path);
      *temp_sum -= node->right->val;
      current_path->pop_back();
    }
  }

  vector<vector<int>> pathSum(TreeNode* node, int target) {
    if (!node) {
      return {};
    }
    int temp_sum = 0;
    std::vector<std::vector<int>> result;
    std::vector<int> current_path;
    DFS(target, node, &result, &temp_sum, &current_path);
    return result;
  }
};