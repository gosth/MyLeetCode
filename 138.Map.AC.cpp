#include<iostream>

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
	RandomListNode * copyRandomList(RandomListNode *head) {
		RandomListNode* ptr = head;
		while (ptr) {
			RandomListNode
			ptr = ptr->next;
		}
		node_vec.push_back(NULL);
		ptr = head;
		i = 0;
		while (ptr) {
			node_vec[i]->next = node_vec[i + 1];
			if (ptr->random) {
				int id = node_map[ptr->random];
				node_vec[i]->random = node_vec[id];
			}
			ptr = ptr->next;
			++i;
		}
		return node_vec.front();
	}
};