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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* result = head;
		if (!head) {
			return result;
		}

		size_t count = 1;
		ListNode* beginPrev = NULL;
		while (count < m) {
			beginPrev = head;
			head = head->next;
			++count;
		}
		ListNode* midBegin = NULL;
		ListNode* midEnd = head;
		ListNode* next = NULL;
		while (count <= n) {
			next = head->next;
			head->next = midBegin;
			midBegin = head;
			head = next;
			++count;
		}
		if (m != 1) {
			beginPrev->next = midBegin;
		}
		else {
			result = midBegin;
		}
		midEnd->next = next;
		return result;
	}
};