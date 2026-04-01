class Solution {
 public:
  Node* insert(Node* head, int insertVal) {
    if (!head) {
      Node* node = new Node(insertVal);
      node->next = node;
      return node;
    }
    if (head->next == head) {
      Node* node = new Node(insertVal, head);
      head->next = node;
      return head;
    }
    Node* current = head;
    Node* next_node = current->next;
    while (true) {
      if (next_node->val < current->val) {
        if (insertVal >= current->val || insertVal <= next_node->val) {
          Node* node = new Node(insertVal, next_node);
          current->next = node;
          return head;
        }
      } else {
        if (insertVal <= next_node->val && insertVal >= current->val) {
          Node* node = new Node(insertVal, next_node);
          current->next = node;
          return head;
        }
      }
      next_node = next_node->next;
      current = current->next;
      if (current == head) {
        Node* node = new Node(insertVal, next_node);
        current->next = node;
        return head;
      }
    }
    return head;
  }
};