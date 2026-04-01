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
    ListNode *MergeTagList(std::vector<std::stack<int>> *stores) {
        int add_bit = 0;
        ListNode *l1 = new ListNode(0);
        while (!stores->front().empty() && !stores->back().empty()) {
            int feature_result = stores->front().top() + stores->back().top() + add_bit;
            ListNode *node = new ListNode(feature_result % 10);
            add_bit = feature_result / 10;
            node->next = l1->next;
            l1->next = node;
            stores->front().pop();
            stores->back().pop();
        }
        while (!stores->front().empty()) {
            int feature_result = stores->front().top() + add_bit;
            ListNode *node = new ListNode(feature_result % 10);
            add_bit = feature_result / 10;
            node->next = l1->next;
            l1->next = node;
            stores->front().pop();
        }
        while (!stores->back().empty()) {
            int feature_result = stores->back().top() + add_bit;
            ListNode *node = new ListNode(feature_result % 10);
            add_bit = feature_result / 10;
            node->next = l1->next;
            l1->next = node;
            stores->back().pop();
        }
        if (add_bit) {
            ListNode *node = new ListNode(add_bit);
            node->next = l1->next;
            l1->next = node;
        }
        return l1->next;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        std::vector<std::stack<int>> stores(2);
        while (l1) {
            stores.front().emplace(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stores.back().emplace(l2->val);
            l2 = l2->next;
        }
        return MergeTagList(&stores);
    }
};