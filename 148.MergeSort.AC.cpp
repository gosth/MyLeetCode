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

  ListNode* cut(ListNode* head, int n) {
    auto pointer = head;
    while (--n && pointer) {
      pointer = pointer->next;
    }
    if (!pointer) {
      return nullptr;
    }
    auto next = pointer->next;
    pointer->next = nullptr;
    return next;
  }

  ListNode* merge(ListNode* left, ListNode* right) {
    ListNode* dummy_head = new ListNode(0);
    auto pointer = dummy_head;
    while (left && right) {
      if (left->val < right->val) {
        pointer->next = left;
        pointer = pointer->next;
        left = left->next;
      } else {
        pointer->next = right;
        pointer = pointer->next;
        right = right->next;
      }
    }
    pointer->next = left ? left : right;
    return dummy_head->next;
  }

  ListNode* sortList(ListNode* head) {
    if (!head) {
      return nullptr;
    }
    ListNode* pointer = head;
    int sequence_length = 0;
    while (pointer) {
      ++sequence_length;
      pointer = pointer->next;
    }
    ListNode* dummy_head = new ListNode(0);
    dummy_head->next = head;
    for (int step = 1; step <= sequence_length; step<<=1) {
      auto current = dummy_head->next;
      auto tail = dummy_head;
      while (current) {
        auto left = current;
        auto right = cut(left, step);
        current = cut(right, step);
        tail->next = merge(left, right);
        while (tail->next) {
          tail = tail->next;
        }
      }
    }
    return dummy_head->next;
  }
};