#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        while (head) {
            ListNode* next_node = head->next;
            head->next = new_head->next;
            new_head->next = head;
            head = next_node;
        }
        return new_head->next;
    }
};