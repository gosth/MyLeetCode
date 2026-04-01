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
    ListNode *traverse_node_1 = headA, *traverse_node_2 = headB;
    bool is_changed = false;
    while (1) {
      if (traverse_node_1 == traverse_node_2) {
        return traverse_node_1;
      }
      if (traverse_node_1->next) {
        traverse_node_1 = traverse_node_1->next;
      } else {
        if (is_changed) {
          return nullptr;
        }
        is_changed = true;
        traverse_node_1 = headB;
      }
      if (traverse_node_2->next) {
        traverse_node_2 = traverse_node_2->next;
      } else {
        traverse_node_2 = headA;
      }
    }
    return nullptr;
  }
};