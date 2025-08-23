#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head==nullptr||head->next==nullptr){return head;}
        ListNode*tail=head->next;
        if (tail->next==nullptr){return head;}
        while(tail->next!=nullptr){
            if (tail->next->val<head->val){
                ListNode*temp=tail->next;
                tail->next=tail->next->next;
                temp->next=head;
                head=temp;
            }
            else if (tail->next->val>head->val && tail->next->val<tail->val){
                ListNode*curr=head;  
                ListNode*temp=tail->next;
                tail->next=temp->next;
                while(curr->next->val<temp->val){
                    curr=curr->next;
                }
                temp->next=curr->next;
                curr->next=temp;
            }
            else{
                tail=tail->next;
            }}
        
        return head;
    }
};
