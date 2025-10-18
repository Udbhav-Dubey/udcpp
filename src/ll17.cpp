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
Node *reverse(Node*head){
    Node*curr=head;
    Node*prev=nullptr;
    Node*nex=nullptr;
    while(curr!=NULL){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
}
void printy(Node *head){
    Node*curr=head;
    while(curr!=NULL){
        cout << curr->data << "-" ;
        curr=curr->next;
    }
    cout << endl;
}
int main(){
    cout << "enter the number of nodes : ";
    int n;
    cin>>n;
    Node*head=nullptr;
    Node*tail=nullptr;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        Node*newnode=new Node(x);
        if (head==nullptr){
            head=newnode;
            tail=newnode;
        } 
        else {tail->next=newnode;
            tail=newnode;
        }
    }
    printy(head);
    head=reverse(head);
    cout << "after reversing : " ;
    printy(head);
    return 0;
}
