class solution{
public :
    Listnode* removeElements(listnode* head,int val){
        while(head!=nullptr && head->val==val){
            head=head->next;
        }
        if (head==nullptr){return head;}
        listnode* curr=head;
        while(curr!=nullptr && curr->next!=nullptr){
            if (curr->next->val==val){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
            }
        }
        return head;
    }
};
