#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next,*prev;
    Node(int data){
        this->data=data;
        this->prev=nullptr;
        this->next=nullptr;
    }
};
Node*del(Node*head,int pos){
    int idx=0;
    Node*curr=head;
    while(idx<pos&&curr!=NULL){
        curr=curr->next;
        idx++;
    }
    if (curr==nullptr){
        return head;
    }
    if (curr->prev!=NULL){
        curr->prev->next=curr->next;
    }
    if (curr->next!=NULL){
        curr->next->prev=curr->prev;
    }
    if (head==curr){
        head=curr->next;
    }
    delete curr;
    return head;
}
void printy(Node*head){
    Node*curr=head;
    while(curr!=NULL){
        cout << curr->data << "-";
        curr=curr->next;
    }
    cout << endl;
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
        if (cin.peek()=='\n') break;
    }
    printy(head);
    cout << "enter the position of deletetion : ";
    int pos;
    cin>>pos;
    head=del(head,pos);
    printy(head);
return 0;
}
