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
void revprinty(Node*tail){
    if (tail==nullptr){
        return ;
    }
    cout << tail->data<<"-" ;
    revprinty(tail->prev);
}
int main (){
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
        else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        }
    }
    revprinty(tail);
return 0;
}
