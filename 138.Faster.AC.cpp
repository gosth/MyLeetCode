class Solution {
public:
	RandomListNode * copyRandomList(RandomListNode *head) {
		if (!head) { return NULL; }
		RandomListNode *newPtr, *ptr = head;
		for (; ptr; ptr = ptr->next->next) {
			RandomListNode* newNode = new RandomListNode(ptr->label);
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
		for (ptr = head; ptr; ptr = ptr->next->next) {
			if (ptr->random) {
				ptr->next->random = ptr->random->next;
			}
		}
		RandomListNode* newHeadPtr = head->next;
		for (ptr = head; ptr; ptr = ptr->next) {
			newPtr = ptr->next;
			ptr->next = ptr->next->next;
			if (newPtr->next) newPtr->next = newPtr->next->next;
		}
		return newHeadPtr;
	}
};