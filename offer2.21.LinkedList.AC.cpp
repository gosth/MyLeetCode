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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *before_delete = new_head;
        before_delete = new_head;
        while (--n) {
            head = head->next;
        }
        while (head->next) {
            before_delete = before_delete->next;
            head = head->next;
        }
        before_delete->next = before_delete->next->next;
        return new_head->next;
    }
};