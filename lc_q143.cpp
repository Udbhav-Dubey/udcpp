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
    void reorderList(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
            ListNode*second=slow->next;
            slow->next=nullptr;
            ListNode*curr=second;
            ListNode*prev=nullptr;
            slow=slow->next;
            while(curr){
                ListNode*nxt=curr->next;
                slow->next=prev;
                prev=curr;
                curr=nxt;
            }
        ListNode*first=head;
        ListNode*other=prev;
        while(other){
            ListNode*tmp1=first->next;
            ListNode*tmp2=other->next;
            first->next=other;
            other->next=tmp1;
            first=tmp1;
            other=tmp2;
        }
    }
};
