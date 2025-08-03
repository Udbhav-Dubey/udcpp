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
    cout<<endl;
}
Node* append(Node*head,int pos,int val){
    Node*newnode=new Node(val);
    if (pos<0){cout << "invalid " ; return head;}
    else if (pos==0){
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return head;
    }
    else{
        int index=0;
        Node*curr=head;
        while(index<pos&&curr!=NULL){
            index++;
            curr=curr->next;
        }
        if (curr==NULL){
            cout << "out of bounds ";
            delete newnode;
            return head;
        }
        newnode->prev=curr;
        newnode->next=curr->next;
        curr->next=newnode;
        if (newnode->next!=NULL){
            newnode->next->prev=newnode;}
            return head;
    }
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
    if(cin.peek()=='\n') break;
    }
    printy(head);
    cout << "where will be the new node inserted : ";
    int pos;
    cin >> pos;
    cout << "what is the data of this new node : ";
    int val;
    cin>>val;
    head=append(head,pos,val);
    printy(head);
return 0;

