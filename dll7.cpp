#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node*prev;
    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
Node*insertatend(Node*head,int new_data){
    Node*new_node=new Node(new_data);
    if (head==NULL){
        head=new_node;
    }
    else {
        Node*curr=head;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next=new_node;
        new_node->prev=curr;
    }
    return head;
}
void printy(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main (){
    Node*head=new Node(5);
    head->next=new Node(10);
    head->next->prev=head;
    head->next->next=new Node(3);
    head->next->next->prev=head->next;
    printy(head);
    head=insertatend(head,55);
    printy(head);
return 0;
}
