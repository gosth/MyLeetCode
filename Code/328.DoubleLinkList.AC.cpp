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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode(0), * evenHead = new ListNode(0), * oddTail = oddHead, * evenTail = evenHead;
        int count = 0;
        while (head) {
            ++count;
            if (count % 2 == 0) {
                // 偶数
                evenTail->next = head;
                evenTail = evenTail->next;
            } else {
                // 奇数
                oddTail->next = head;
                oddTail = oddTail->next;
            }
            head = head->next;
            oddTail->next = nullptr;
            evenTail->next = nullptr;
        }
        if (oddTail) {
            oddTail->next = evenHead->next;
        }
        return oddHead->next;
    }
};

