class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* tail = head; 

        while (tail->next) {
            if (tail->next->val >= tail->val) {
                tail = tail->next;
            } else {
                ListNode* temp = tail->next;
                tail->next = temp->next;
                ListNode* curr = dummy;
                while (curr->next->val < temp->val) {
                    curr = curr->next;
                }
                temp->next = curr->next;
                curr->next = temp;
            }
        }
        return dummy->next;
    }
};

