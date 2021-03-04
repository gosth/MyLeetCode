/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) {
      return nullptr;
    }
    ListNode* node1 = headA, * node2 = headB;
    while (1) {
      if (node1 == node2) {
        return node1;
      }
      if (!node1->next && !node2->next) {
        return nullptr;
      }
      if (node1->next) {
        node1 = node1->next;
      } else {
        node1 = headB;
      }
      if (node2->next) {
        node2 = node2->next;
      } else {
        node2 = headA;
      }
    }
    return nullptr;
  }
};