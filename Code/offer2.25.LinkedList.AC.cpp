#include <iostream>

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
    ListNode *ReverseLinkedList(ListNode *l1) {
        ListNode *next_node = nullptr, *haed = new ListNode(0);
        while (l1) {
            next_node = l1->next;
            l1->next = haed->next;
            haed->next = l1;
            l1 = next_node;
        }
        return haed->next;
    }

    ListNode *Add(ListNode *l1, ListNode *l2) {
        ListNode *haed = new ListNode(0);
        int add_bit = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + add_bit;
            add_bit = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            node->next = haed->next;
            haed->next = node;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int sum = l1->val + add_bit;
            add_bit = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            node->next = haed->next;
            haed->next = node;
            l1 = l1->next;
        }
        while (l2) {
            int sum = l2->val + add_bit;
            add_bit = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            node->next = haed->next;
            haed->next = node;
            l2 = l2->next;
        }
        if (add_bit) {
            ListNode *node = new ListNode(add_bit);
            node->next = haed->next;
            haed->next = node;
        }
        return haed->next;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode *new_l1 = ReverseLinkedList(l1);
        ListNode *new_l2 = ReverseLinkedList(l2);
        return Add(new_l1, new_l2);
    }
};