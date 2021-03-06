#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode * partition(ListNode* head, int x) {
		if (!head) { return NULL; }
		ListNode* lessThanX = NULL, *lessThanXHead = NULL;
		ListNode* greaterOrEqualX = NULL, *greaterOrEqualXHead = NULL;
		while (head) {
			if (head->val < x) {
				if (lessThanX && lessThanXHead) {
					lessThanX->next = head;
					head = head->next;
					lessThanX = lessThanX->next;
					lessThanX->next = NULL;
				}
				else {
					lessThanXHead = head;
					lessThanX = head;
					head = head->next;
					lessThanX->next = NULL;
				}
			}
			else {
				if (greaterOrEqualX && greaterOrEqualXHead) {
					greaterOrEqualX->next = head;
					head = head->next;
					greaterOrEqualX = greaterOrEqualX->next;
					greaterOrEqualX->next = NULL;
				}
				else {
					greaterOrEqualXHead = head;
					greaterOrEqualX = head;
					head = head->next;
					greaterOrEqualX->next = NULL;
				}
			}
		}
		if (!lessThanXHead) {
			return greaterOrEqualXHead;
		}
		else {
			lessThanX->next = greaterOrEqualXHead;
			return lessThanXHead;
		}
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

int stringToInteger(string input) {
	return stoi(input);
}

string listNodeToString(ListNode* node) {
	if (node == nullptr) {
		return "[]";
	}

	string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		ListNode* head = stringToListNode(line);
		getline(cin, line);
		int x = stringToInteger(line);

		ListNode* ret = Solution().partition(head, x);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}