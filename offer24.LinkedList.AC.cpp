class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head) {
      return nullptr;
    }
    ListNode* new_head = new ListNode(0);
    ListNode* current_node;
    while (head) {
      current_node = head;
      head = head->next;
      current_node->next = new_head->next;
      new_head->next = current_node;
    }
    return new_head->next;
  }
};