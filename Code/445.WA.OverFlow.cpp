
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    class Solution {
    public:
        unsigned long long transLinkedListToInt(ListNode* listNode) {
            unsigned long long value = 0;
            while (listNode) {
                value = value * 10 + listNode->val;
                listNode = listNode->next;
            }
            return value;
        }

        ListNode* transIntToLinkedList(unsigned long long value) {
            std::vector<unsigned long long> store;
            while (value) {
                store.emplace_back(value % 10);
                value /= 10;
            }
            ListNode* head = new ListNode(0, nullptr);
            ListNode* current = head;
            for (auto rIter = store.rbegin(); rIter != store.rend(); ++rIter) {
                ListNode* feature = new ListNode(*rIter, nullptr);
                current->next = feature;
                current = current->next;
            }
            return head->next;
        }

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            auto value1 = transLinkedListToInt(l1);
            auto value2 = transLinkedListToInt(l2);
            auto value3 = value1 + value2;
            if (!value3) {
                return new ListNode(0, nullptr);
            }
            return transIntToLinkedList(value3);
        }
    };