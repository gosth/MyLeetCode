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
	ListNode* reverseList(ListNode* head) {
		ListNode* newListCur = NULL, *originalNext = NULL;
		while (head) {
			originalNext = head->next;
			head->next = newListCur;
			newListCur = head;
			head = originalNext;
		}
		return newListCur;
	}
};