#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <unordered_map>

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

    ListNode *Cut(ListNode *node, int length) {
        while (node && --length) {
            node = node->next;
        }
        if (!node) {
            return nullptr;
        }
        ListNode *feature = node->next;
        node->next = nullptr;
        return feature;
    }

    ListNode *Merge(ListNode *left, ListNode *right) {
        ListNode *dummy_head = new ListNode(0);
        ListNode *tail = dummy_head;
        while (left && right) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
                tail = tail->next;
                tail->next = nullptr;
            } else {
                tail->next = right;
                right = right->next;
                tail = tail->next;
                tail->next = nullptr;
            }
        }
        if (left) {
            tail->next = left;
        }
        if (right) {
            tail->next = right;
        }
        return dummy_head->next;
    }

    ListNode *sortList(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        for (int step = 1; step <= length; step *= 2) {
            ListNode *current = dummy_head->next;
            ListNode *tail = dummy_head;
            while (current) {
                ListNode *left = current;
                current = Cut(current, step);
                ListNode *right = current;
                current = Cut(current, step);
                ListNode *merged = Merge(left, right);
                tail->next = merged;
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummy_head->next;
    }
};

int main() {

    LRUCache *obj = new LRUCache(2);
    obj->put(2, 1);
    obj->put(1, 1);
    int param_1;
    cout << obj->get(2) << std::endl;
    obj->put(4, 1);
    cout << obj->get(1) << std::endl;
//     cout << "list " << obj->data_store_.size() << endl;
//     cout << "map " << obj->data_index_.size() << endl;
//     for (const auto& item : obj->data_index_) {
//         cout << "key=" << item.first <<endl;
//     }
    cout << obj->get(2) << std::endl;


}