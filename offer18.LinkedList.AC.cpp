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
        ListNode *deleteNode(ListNode *head, int val) {
            if (nullptr == head) {
                return nullptr;
            }
            ListNode *new_header = new ListNode(0);
            new_header->next = head;
            ListNode *prev = new_header;
            while (head) {
                if (val == head->val) {
                    prev->next = head->next;
                    break;
                }
                prev = prev->next;
                head = head->next;
            }
            return new_header->next;
        }
    };