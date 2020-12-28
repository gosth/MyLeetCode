class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (!head || !head->next) {
                return head;
            }
            ListNode* newHead = new ListNode(0, head);
            ListNode* front = head;
            ListNode* last = head->next;
            ListNode* featureIndex1 = newHead, * featureIdex2 = last->next;
            while (1) {
                featureIndex1->next = last;
                last->next = front;
                front->next = featureIdex2;
                featureIndex1 = front;
                if (!featureIndex1->next) {
                    break;
                }
                front = featureIndex1->next;
                if (!front->next) {
                    break;
                }
                last = front->next;
                featureIdex2 = last->next;
            }
            return newHead->next;
        }
    };