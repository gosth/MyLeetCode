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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return head;
        }
        ListNode* prevDelNode = new ListNode(0);
        prevDelNode->next = head;
        ListNode* resultHead = head;
        while (--n) {
            head = head->next;
        }
        while (head->next) {
            head = head->next;
            prevDelNode = prevDelNode->next;
        }
        bool isDelHeadNode = false;
        if (prevDelNode->next == resultHead) {
            isDelHeadNode = true;
        }
        prevDelNode->next = prevDelNode->next->next;
        if (isDelHeadNode) {
            resultHead = prevDelNode->next;
        }
        return resultHead;
    }
};