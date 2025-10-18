#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
int main (){
    Node*head=nullptr;
    Node*tail=nullptr;
    int x;
    while(cin>>x){
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
        if (cin.peek()=='\n') break;
    }
return 0;
}
