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
  void BuildPath(TreeNode* current_node,
                 TreeNode* p,
                 TreeNode* q,
                 std::vector<std::vector<TreeNode*>>* path,
                 std::vector<TreeNode*>* temp_path) {
    if (!path->front().empty() && !path->back().empty()) {
      return;
    }
    if (!current_node) {
      return;
    }
    temp_path->emplace_back(current_node);
    if (p == current_node) {
      path->front() = *temp_path;
    }
    if (q == current_node) {
      path->back() = *temp_path;
    }
    BuildPath(current_node->left, p, q, path, temp_path);
    BuildPath(current_node->right, p, q, path, temp_path);
    temp_path->pop_back();
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
      return nullptr;
    }
    std::vector<std::vector<TreeNode*>> path(2);
    std::vector<TreeNode*> temp_path;
    BuildPath(root, p, q, &path, &temp_path);
    const auto min_path_size = std::min(path.front().size(), path.back().size());
    size_t index = 0;
    for (; index < min_path_size; ++index) {
      if (path.front()[index] != path.back()[index]) {
        break;
      }
    }
    return path.front()[index - 1];
  }
};