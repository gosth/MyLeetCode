class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    std::string serialize_data;
    if (!root) {
      return serialize_data;
    }
    std::deque<TreeNode*> node_deque;
    node_deque.emplace_back(root);
    while (!node_deque.empty()) {
      int queue_size = node_deque.size();
      for (int index = 0; index < queue_size; ++index) {
        const auto current_node = node_deque.front();
        if (current_node) {
          serialize_data += std::to_string(current_node->val) + ",";
          node_deque.emplace_back(current_node->left);
          node_deque.emplace_back(current_node->right);
        } else {
          serialize_data += "n,";
        }
        node_deque.pop_front();
      }
    }
    return serialize_data;
  }

  // Decodes your encoded current_node to tree.
  TreeNode* deserialize(string current_node) {
    if (current_node.empty() || current_node.front() == 'n') {
      return nullptr;
    }
    std::vector<std::string> data_elements;
    int current_node_index = 0;
    for (int index = 0; index < current_node.size(); ++index) {
      if (current_node[index] == ',') {
        data_elements.emplace_back(
            current_node.substr(current_node_index, index - current_node_index));
        current_node_index = index + 1;
      }
    }
    TreeNode* root_node = new TreeNode(std::stoi(data_elements.front()));
    std::deque<TreeNode*> node_deque;
    node_deque.emplace_back(root_node);
    for (int i = 1; i < data_elements.size();) {
      if (data_elements[i] != "n") {
        auto node = new TreeNode(std::stoi(data_elements[i]));
        node_deque.emplace_back(node);
        node_deque.front()->left = node;
      }
      ++i;
      if (data_elements[i] != "n") {
        auto node = new TreeNode(std::stoi(data_elements[i]));
        node_deque.emplace_back(node);
        node_deque.front()->right = node;
      }
      node_deque.pop_front();
      ++i;
    }
    return root_node;
  }
};