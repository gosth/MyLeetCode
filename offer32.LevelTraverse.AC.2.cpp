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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
      return {};
    }
    std::deque<TreeNode*> deque;
    std::vector<std::vector<int>> result;
    deque.emplace_back(root);
    while (!deque.empty()) {
      std::vector<int> level_store;
      int current_level_size = deque.size();
      for (int index = 0; index < current_level_size; ++index) {
        const auto current_item = deque.front();
        level_store.emplace_back(current_item->val);
        if (current_item->left) {
          deque.emplace_back(current_item->left);
        }
        if (current_item->right) {
          deque.emplace_back(current_item->right);
        }
        deque.pop_front();
      }
      result.emplace_back(level_store);
    }
    return result;
  }
};