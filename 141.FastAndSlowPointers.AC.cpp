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
	bool hasCycle(ListNode *head) {
		ListNode *fast = NULL, *slow = NULL;
		if (head && head->next) {
			slow = head->next;
		}
		else {
			return false;
		}
		if (slow->next) {
			fast = slow->next;
		}
		else {
			return false;
		}
		while (fast) {
			if (slow == fast) {
				return true;
			}
			if (slow->next) {
				slow = slow->next;
			}
			else {
				return false;
			}
			if (fast->next && fast->next->next) {
				fast = fast->next->next;
			}
			else {
				return false;
			}
		}
	}
};