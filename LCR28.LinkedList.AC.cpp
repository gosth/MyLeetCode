#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* MergeLinkedList(Node* head) {
        if (!head) {
            return nullptr;
        }
        Node* current = head;
        while (current) {
            if (current->child) {
                Node* current_next = current->next;
                current->next = MergeLinkedList(current->child);
                current->next->prev = current;
                while (current->next) {
                    current->child = nullptr;
                    current = current->next;
                }
                if (current_next) {
                    current_next->prev = current;
                }
                current->next = current_next;
            }
            current = current->next;
        }
        return head;
    }

    Node* flatten(Node* head) {
        if (!head) {
            return nullptr;
        }
        return MergeLinkedList(head);
    }
};






