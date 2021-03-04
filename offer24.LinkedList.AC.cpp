class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head) {
      return nullptr;
    }
    ListNode* new_head_header = new ListNode(0);
    while (head) {
      ListNode* new_node = new ListNode(head->val);
      new_node->next = new_head_header->next;
      new_head_header->next = new_node;
      head = head->next;
    }
    return new_head_header->next;
  }
};