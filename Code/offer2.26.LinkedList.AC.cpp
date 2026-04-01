class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head) {
      return;
    }
    ListNode* dummy_head = new ListNode(0, head);
    std::vector<ListNode*> node_store;
    while (head) {
      node_store.emplace_back(head);
      head = head->next;
    }
    ListNode* current = dummy_head;
    for (int index = 0; index < node_store.size() / 2; ++index) {
      current->next = node_store[index];
      current = current->next;
      current->next = node_store[node_store.size() - 1 - index];
      current = current->next;
    }
    if (node_store.size() % 2) {
      // 奇数
      current->next = node_store[node_store.size() / 2];
      current = current->next;
    }
    current->next = nullptr;
    head = dummy_head->next;
  }
};