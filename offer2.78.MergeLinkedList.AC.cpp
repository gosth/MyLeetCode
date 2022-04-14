#include <iostream>
#include <set>
#include <vector>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        ListNode* dummy_node = new ListNode();
        ListNode* merged_last_node = dummy_node;
        bool finish = false;
        while (!finish) {
            int min_value = INT_MAX;
            int min_index = INT_MAX;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i]) {
                    if (lists[i]->val < min_value) {
                        min_value = lists[i]->val;
                        min_index = i;
                    }
                }
            }
            if (min_value != INT_MAX) {
                merged_last_node->next = lists[min_index];
                merged_last_node = merged_last_node->next;
                lists[min_index] = lists[min_index]->next;
                merged_last_node->next  = nullptr;
            } else {
                finish = true;
            }
        }
        return dummy_node->next;
    }
};