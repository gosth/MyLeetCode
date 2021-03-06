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
		set<ListNode*> NodeSet;
		while (head) {
			if (NodeSet.find(head) != NodeSet.end()) {
				return true;
			}
			else {
				NodeSet.insert(head);
				head = head->next;
			}
		}
		return false;
	}
};