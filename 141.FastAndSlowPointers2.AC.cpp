class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *fast = head, *slow = head;
		while (head) {
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
			if (slow == fast) {
				return true;
			}
		}
		return false;
	}
};