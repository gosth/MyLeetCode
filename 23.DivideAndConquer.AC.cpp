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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) {
			return l2;
		}
		if (!l2) {
			return l1;
		}
		ListNode* head = new ListNode(0);
		ListNode* pre = head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				pre->next = l1;
				pre = l1;
				l1 = l1->next;
				pre->next = 0;
			}
			else {
				pre->next = l2;
				pre = l2;
				l2 = l2->next;
				pre->next = 0;
			}
		}
		if (!l1) {
			pre->next = l2;
		}
		if (!l2) {
			pre->next = l1;
		}
		return head->next;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) {
			return NULL;
		}
		if (1 == lists.size()) {
			return lists.front();
		}
		if (2 == lists.size()) {
			return mergeTwoLists(lists.front(), lists.back());
		}
		size_t mid = lists.size() / 2;
		vector < ListNode * > firstPart;
		vector < ListNode * > secondPart;
		for (size_t i = 0; i < mid; ++i) {
			firstPart.push_back(lists[i]);
		}
		for (size_t i = mid; i < lists.size(); ++i) {
			secondPart.push_back(lists[i]);
		}
		ListNode* l1 = mergeKLists(firstPart);
		ListNode* l2 = mergeKLists(secondPart);
		return mergeTwoLists(l1, l2);
	}
};