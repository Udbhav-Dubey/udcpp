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
    ListNode* merge(ListNode* l1,ListNode *l2){
        if (!l1){return l2;}
        if (!l2){return l1;}
        if (!l1&&!l2){return NULL;}
        ListNode *head;
        if (l1->val<=l2->val){
            head=l1;
            l1=l1->next;

        }
        else {
            head=l2;
            l2=l2->next;
        }
        List Node*curr=head; // k hai yeh 
        while(l1!=NULL&&l2!=NULL){
            if (l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
            }
            else {
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1!=NULL){
            curr->next=l1;
        }       
        if(l2!=NULL){
            curr->next=l2;
            }
        }
        return head;
    }    
public:

    ListNode* sortList(ListNode* head) {
        if (!head||!head->next){return head;}
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *prev=NULL;
        while(fast || fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        ListNode*mid=prev;
        ListNode*head2=mid->next;
        mid->next=NULL;
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(head2);
        return merge(l1,l2);

    }
};
