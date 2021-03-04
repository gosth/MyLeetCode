class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* headNode = new ListNode(0);
    ListNode* currentNode = headNode;
    while (l1 && l2) {
      if (l1->val > l2->val) {
        currentNode->next = l2;
        l2 = l2->next;
      } else {
        currentNode->next = l1;
        l1 = l1->next;
      }
      currentNode = currentNode->next;
    }
    l1 == nullptr ? currentNode->next = l2 : currentNode->next = l1;
    return headNode->next;
  }
};