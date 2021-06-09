class Solution {
 public:
  vector<int> levelOrder(TreeNode* root) {
    if (!root) {
      return std::vector<int>();
    }
    std::deque<TreeNode*> store;
    std::vector<int> result;
    store.emplace_back(root);
    while (!store.empty()) {
      const auto& current_node = store.front();
      if (current_node->left) {
        store.emplace_back(current_node->left);
      }
      if (current_node->right) {
        store.emplace_back(current_node->right);
      }
      result.emplace_back(current_node->val);
      store.pop_front();
    }
    return result;
  }
};