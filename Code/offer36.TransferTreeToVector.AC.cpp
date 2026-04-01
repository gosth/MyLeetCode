class Solution {
 public:
  void Trans2BST(Node* node, std::vector<Node*>* sequence) {
    if (!node) {
      return;
    }
    if (node->left) {
      Trans2BST(node->left, sequence);
    }
    sequence->emplace_back(node);
    if (node->right) {
      Trans2BST(node->right, sequence);
    }
  }

  Node* treeToDoublyList(Node* root) {
    if (!root) {
      return nullptr;
    }
    std::vector<Node*> sequence;
    Trans2BST(root, &sequence);
    for (auto iter = sequence.begin(); iter != sequence.end() - 1; ++iter) {
      (*iter)->right = *(iter + 1);
    }
    for (auto iter = sequence.rbegin(); iter != sequence.rend() - 1; ++iter) {
      (*iter)->left = *(iter + 1);
    }
    sequence.front()->left = sequence.back();
    sequence.back()->right = sequence.front();
    return sequence.front();
  }
};