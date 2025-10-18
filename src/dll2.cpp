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
void printyrecur(Node*head){
    if (head==nullptr){
        return ;
    }
    cout << head->data << "-";
    printyrecur(head->next);
}
void printy(Node *head){
    Node*curr=head;
    while(curr!=nullptr){
        cout << curr->data << "-";
        curr=curr->next;
    }
    cout << endl;
}
int main (){
cout << "enter the number of nodes : ";
int n;
cin>>n;
Node*head=nullptr;
Node*tail=nullptr;
for (int i=0;i<n;i++){
    cout << "enter the element at place : " << i+1 << " ";
    int x;
    cin>>x;
    Node*newnode=new Node(x);
    if (head==nullptr){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
printy(head);
printyrecur(head);
return 0;
}
