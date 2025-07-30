#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
Node *reverse(Node*head){
    if (head==NULL || head->next==NULL){
        return head;
    }
    Node *rest=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
}
void printy(Node *head){
    Node*curr=head;
    while(curr!=NULL){
        cout << curr->data << "-";
        curr=curr->next;
    }
    cout << endl;
}
int main (){
    cout << "insert elements by spaces " << endl;
    int x;
    Node*head=nullptr;
    Node*tail=nullptr;
    while(cin>>x){
        Node*newnode=new Node(x);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        if (cin.peek()=='\n') break;
    }
    printy(head);
    head=reverse(head);
    cout << "after reversing \n";
    printy(head);
return 0;
}
