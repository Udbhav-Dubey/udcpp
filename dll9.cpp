#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*prev,*next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
void printy(Node*head){
    Node*curr=head;
    while(curr!=NULL){
        cout << curr->data << "-";
        curr=curr->next;
    }
    cout << endl;
}
int main (){
    Node*head=nullptr;
    Node*tail=nullptr;
    cout << "enter the number of nodes : ";
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        Node*newnode=new Node(x);
        if (head==NULL){
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
    head=head->next;
    head->prev=nullptr;
    printy(head);
return 0;
}
