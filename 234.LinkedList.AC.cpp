/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* ReverseLinkedList(ListNode* head) {
    ListNode* new_head = new ListNode(0);
    while (head) {
      ListNode* current_node = head;
      head = head->next;
      current_node->next = new_head->next;
      new_head->next = current_node;
    }
    return new_head->next;
  }

  bool isPalindrome(ListNode* head) {
    ListNode* node_pointer_2 = head;
    int node_count = 0;
    while (node_pointer_2) {
      ++node_count;
      node_pointer_2 = node_pointer_2->next;
    }
    if (1 == node_count) {
      return true;
    }
    int pre_mid_node_index = node_count % 2 == 1 ? node_count / 2 : (node_count - 1) / 2;
    int pre_mid_node_index_2 = pre_mid_node_index;
    node_pointer_2 = head;
    while (pre_mid_node_index_2--) {
      node_pointer_2 = node_pointer_2->next;
    }
    ListNode* node_pointer_3 = node_pointer_2;
    node_pointer_2->next = ReverseLinkedList(node_pointer_2->next);
    node_pointer_2 = node_pointer_2->next;
    while (node_pointer_2) {
      if (node_pointer_2->val == head->val) {
        node_pointer_2 = node_pointer_2->next;
        head = head->next;
      } else {
        ReverseLinkedList(node_pointer_3->next);
        return false;
      }
    }
    ReverseLinkedList(node_pointer_3->next);
    return true;
  }
};