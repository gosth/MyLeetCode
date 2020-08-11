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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* currentNode = head;
        std::deque<int> indexStore;
        std::vector<int> valueStore, result;
        int index = 0;
        while (currentNode) {
            while (!indexStore.empty() && valueStore[indexStore.back()] < currentNode->val) {
                result[indexStore.back()] = currentNode->val;
                indexStore.pop_back();
            }
            valueStore.emplace_back(currentNode->val);
            indexStore.emplace_back(index);
            result.emplace_back(0);
            ++index;
            currentNode = currentNode->next;
        }
        return result;
    }
};