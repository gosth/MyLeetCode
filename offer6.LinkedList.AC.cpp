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
  vector<int> reversePrint(ListNode* head) {
    if (!head) {
      return {};
    }
    std::vector<int> result;
    while (head) {
      result.emplace_back(head->val);
      head = head->next;
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};