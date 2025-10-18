#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
int findLength(Node* head){
    Node* curr=head;
    int ctr=0;
    while(curr!=NULL){
    ctr++;
    curr=curr->next;
    }
    return ctr;
}
int main (){
    int x;
    Node *head=nullptr;
    Node *tail=nullptr;
    while(cin>>x){
    Node *newNode=new Node(x);
    if (head==nullptr){
        head=newNode;
        tail=newNode;
    }
    else {
        tail->next=newNode;
        tail=newNode;
    }
    if (cin.peek()=='\n') break;
    }
    cout << "your length is"<< findLength(head);
return 0;
}
