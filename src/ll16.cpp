#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=next;
    }
};
void printy(Node *head){
    Node*curr=head;
    while(curr!=NULL){
        cout << curr->data << "-" ;
        curr=curr->next;
    }
}
Node *modify(Node *head,int pos,int val){
    Node *curr=head;
    int index=0;
    while(curr!=NULL && index<pos){
        curr=curr->next;
        index++;
    }
    if (curr==NULL){cout << "no such position ";}
    else{curr->data=val;}
    return head;
}
int main (){
    cout << "enter the elements : ";
    int x;
    Node *head=nullptr;
    Node *tail=nullptr;
    while(cin>>x){
        Node *newnode=new Node(x);
        if (head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        if (cin.peek()=='\n'){ break;}
    }
    printy(head);
    cout << "enter the position at which to replace 0 based indexing wise : ";
    int pos;
    cin >> pos;
    int val;
    cout << "enter the value to be replaced with : ";
    cin >> val;
    head=modify(head,pos,val);
    printy(head);
return 0;
}
