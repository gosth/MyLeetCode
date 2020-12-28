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
    void transData(ListNode* listNode, std::stack<int>* stackStore) {
        while (listNode) {
            stackStore->emplace(listNode->val);
            listNode = listNode->next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> stackStore1, stackStore2;
        transData(l1, &stackStore1);
        transData(l2, &stackStore2);
        int carryBit = 0;
        int firstNum = 0, secondNum = 0;
        ListNode* header = new ListNode(0);
        while (!stackStore1.empty() || !stackStore2.empty() || carryBit) {
            firstNum = 0;
            secondNum = 0;
            if (!stackStore1.empty()) {
                firstNum = stackStore1.top();
                stackStore1.pop();
            }
            if (!stackStore2.empty()) {
                secondNum = stackStore2.top();
                stackStore2.pop();
            }
            int sum = firstNum + secondNum + carryBit;
            ListNode* currentNode = new ListNode(sum % 10);
            carryBit = sum / 10;
            currentNode->next = header->next;
            header->next = currentNode;
        }
        return header->next;
    }
};