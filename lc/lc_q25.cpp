#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head||k==1)return head;
        int length=0;
        ListNode*curr=head;
        while(curr){
            curr=curr->next;
            length++;
        }
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev=&dummy;
        while(length>=k){
            ListNode*curr=prev->next;
            ListNode*next=curr->next;
            for (int i=1;i<k;i++){
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
            }
            prev=curr;
            length-=k;
        }
        return dummy.next;
    }
};
