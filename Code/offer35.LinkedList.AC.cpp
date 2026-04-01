/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return nullptr;
    }
    Node* original_list_new_head = new Node(0);
    original_list_new_head->next = head;
    Node* new_list_new_head = new Node(0);
    Node* prev = new_list_new_head;
    std::map<Node*, Node*> mapping;
    while (head) {
      Node* current_item = new Node(head->val);
      mapping.emplace(head, current_item);
      prev->next = current_item;
      prev = prev->next;
      head = head->next;
    }
    for (const auto& [old_history, new_history] : mapping) {
      if (old_history->random) {
        new_history->random = mapping[old_history->random];
      }
    }
    return new_list_new_head->next;
  }
};