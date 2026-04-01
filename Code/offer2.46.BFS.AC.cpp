class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    if (!root) {
      return {};
    }
    std::deque<TreeNode*> node_deque;
    std::vector<int> result;
    node_deque.emplace_back(root);
    while (!node_deque.empty()) {
      int level_size = node_deque.size();
      for (int index = 0; index < level_size; ++index) {
        auto current_node = node_deque.front();
        if (current_node->left) {
          node_deque.emplace_back(current_node->left);
        }
        if (current_node->right) {
          node_deque.emplace_back(current_node->right);
        }
        if (index == level_size - 1) {
          result.emplace_back(current_node->val);
        }
        node_deque.pop_front();
      }
    }
    return result;
  }
};