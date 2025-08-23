class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*curr1=head;
        int length=0;
        while(curr1->next){
            curr1=curr1->next;
            length++;
        }
        curr1->next=head;
        length++;
        k=k%length;
        n=length-k-1;
        ListNode*curr=head;
        for (int i=0;i<n;i++){
            curr=curr->next;
        }
        curr->next=nullptr;
        return head;
    }
};
