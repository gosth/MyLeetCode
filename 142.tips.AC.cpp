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
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head, *slow = head;
		while (head) {
			if (slow->next) {
				slow = slow->next;
			}
			else {
				return NULL;
			}
			if (fast->next && fast->next->next) {
				fast = fast->next->next;
			}
			else {
				return NULL;
			}
			if (slow == fast) {
				break;
			}
		}
		if (!head) {
			return NULL;
		}
		else {
			while (head != fast) {
				head = head->next;
				fast = fast->next;
				if (head == fast) {
					return head;
				}
			}
			return head;
		}
	}
};