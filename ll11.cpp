#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
Node * append(Node* head,int vaf){
    Node *newnode=new Node(vaf);
    if (head==nullptr){
        return newnode;
    }
    Node * last=head;
    while(last->next!=nullptr){
        last=last->next;
    }
    last->next=newnode;
    return head;
}
void printy(Node* head){
    while(head!=NULL){
        cout << " " <<head->data;
        head=head->next;
    }
}
int main(){
    Node* head=new Node(10);
    head->next=new Node(5);
    head->next->next=new Node(3);
    head->next->next->next=new Node(1);
    printy(head);
    cout << "\nenter the variable to insert : ";
    int vaf;
    cin>>vaf;
    head=append(head,vaf);
    cout << "after inserting : ";
    printy(head);
return 0;
}
