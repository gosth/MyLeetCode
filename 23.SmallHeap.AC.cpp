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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		std::priority_queue<int, std::vector<int>, std::greater<int> > smallHeap;
		ListNode* head = new ListNode(0);
		ListNode* pre = head;
		for (size_t i = 0; i < lists.size(); ++i) {
			ListNode* item = lists[i];
			while (item) {
				smallHeap.push(item->val);
				item = item->next;
			}
		}
		while (!smallHeap.empty()) {
			pre->next = new ListNode(smallHeap.top());
			pre = pre->next;
			smallHeap.pop();
		}
		return head->next;
	}
};