#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next,*prev;
    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
int findsize(Node*head){
    int size=0;
    while(head!=nullptr){
        size++;
        head=head->next;
    }
    return size;
}
int fisi(Node *head){
    int size=0;
    while(head!=NULL){
        size++;
        head=head->next;
    }
    return size;
}
int main (){
    int x;
    Node*head=nullptr;
    Node*tail=nullptr;
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
        if (cin.peek()=='\n')break;
    }
cout << findsize(head)<<endl;;
cout <<fisi(head)<<endl;
return 0;
}
