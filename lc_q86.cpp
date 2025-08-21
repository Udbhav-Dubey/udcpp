class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode bdummy(0),adummy(0);
        ListNode *before=&bdummy,*after=&adummy;
        while(head){
            if (head->val<x){
                before->next=head;
                before=before->next;
            }
            else {
                after->next=head;
                after=after->next;
            }
            head=head->next;
        }
        after->next=nullptr;
        before->next=adummy.next;
        return bdummy.next;
    }
};
