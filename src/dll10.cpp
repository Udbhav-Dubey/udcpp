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
void printy(Node*head){
    Node*curr=head;
    while(curr!=NULL){
        cout << curr->data << "-";
        curr=curr->next;
    }
    cout << endl;
}
Node*delend(Node*head){
    if (head==nullptr){return nullptr;}
    if (head->next==nullptr){delete head;return nullptr;}
    Node*curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->prev->next=NULL;
    delete curr;
    return head;
}
Node*dend(Node*head,Node*&tail){
    if(tail==nullptr){}
    else if(head==tail){
        delete tail;
        head=nullptr;
        tail=nullptr;
    }
    else{
        Node*temp=tail;
        tail=tail->prev;
        tail->next=nullptr;
        delete temp;
    }
    return head;
}
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
    printy(head);
    head=delend(head);
    printy(head);
    head=dend(head,tail);
    printy(head);
return 0;
}
