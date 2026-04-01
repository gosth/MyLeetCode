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
 ListNode* reverse(ListNode* start, ListNode* end) {
     ListNode* dummy_node = new ListNode();
     while (start) {
         ListNode* next_node = start->next;
         if (dummy_node->next) {
             start->next = dummy_node->next;
         }
         dummy_node->next = start;
         start = next_node;
     }
    return dummy_node->next;
 }
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy_node = new ListNode();
        dummy_node->next = head;
        ListNode *pre_node = dummy_node, *next_node = nullptr;
        int count = 0;
        while (head) {
            ++count;
            if (k == count) {
                count = 0;
                next_node = head->next;
                head->next = nullptr;
                ListNode* reversed_tail = pre_node->next;
                pre_node->next = reverse(pre_node->next, head);
                reversed_tail->next = next_node;
                pre_node = reversed_tail;
                head = reversed_tail;
            }
            head = head->next;
        }
        return dummy_node->next;
    }
};