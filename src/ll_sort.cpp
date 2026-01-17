#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node*next;
    Node(int x){
        val=x;
        next=NULL;
    }
};
Node* merge(Node* l1,Node*l2){
    if (!l1&&!l2){return NULL;}
    if (!l2){return l1;}
    if (!l1){return l2;}
    Node*head=NULL;
    if (l1->val<=l2->val){
        head=l1;
        l1=l1->next;
    }
    else {
        head=l2;
        l2=l2->next;
    }
    Node*curr=head;
    while(l1&&l2){
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
    if (!l1){
        curr->next=l2;
    }
    if (!l2){
        curr->next=l1;
    }
    return head;
}
Node* sorting(Node* head){
    if (!head||!head->next){return head;}
    Node*slow=head,*fast=head,*prev=NULL;
    while(fast&&fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    Node*mid=prev;
    Node*head2=prev->next;
    mid->next=NULL;
    Node*l1=sorting(head);
    Node*l2=sorting(head2);
    return merge(l1,l2);
}
void printlist(Node*head){
if (!head){return ;}
Node*curr=head;
while(curr!=NULL){
    cout << curr->val << " ";
    curr=curr->next;
}
}
int main (){
    int n;
    cout << "number of nodes?";
    cin>>n;
    Node *head=nullptr;
    Node *tail=nullptr;
    for (int i=0;i<n;i++){
        int val;
        cout << "enter value for node :"<< i+1 << ":";
        cin >> val;
        Node *newNode= new Node(val);
        if (head==nullptr){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    cout << "linked list :" << endl;
    printlist(head);
    cout << "sorted list : " << endl;
    head=sorting(head);
    printlist(head);
    return 0;
}
