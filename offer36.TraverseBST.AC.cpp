class Solution {
 public:
  void Trans2BST(
      Node* node) {
    if (!node) {
      return;
    }
    if (node->left) {
      Trans2BST(node->left);
    }
    if (!head) {
        head = node;
    }
    if (!prev) {
        prev = node;
    } else {
        prev->right = node;
        node->left = prev;
        prev = node;
    }
    if (node->right) {
      Trans2BST(node->right);
    }
  }

  Node* treeToDoublyList(Node* root) {
    if (!root) {
      return nullptr;
    }
    Trans2BST(root);
    prev->right = head;
    head->left = prev;
    return head;
  }
  Node* head = nullptr;
  Node* prev = nullptr;
};