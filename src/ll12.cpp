#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
Node *insertval(Node *head,int val,int pos){
    if (pos<0){return head;}
    if (pos==1){
        Node *newnode=new Node(val);
        newnode->next=head;
        return newnode;
   }
    Node *curr=head;
    for (int i=1;i<pos-1&&curr!=nullptr;i++){
        curr=curr->next;
    }
    if (curr==nullptr){
        return head;
    }
    Node *newnode=new Node(val);
    newnode->next=curr->next;
    curr->next=newnode;
    return head;
}
void printy(Node *head){    
    Node *curr=head;
    while(curr!=NULL){
        cout << curr->data << "-";
        curr=curr->next;
    }
    cout << endl;
}
int main (){
    cout << "fill the linked list : ";
    int x;
    Node*head=nullptr;
    Node*tail=nullptr;
    while(cin>>x){
        Node *newnode=new Node(x);
        if (head==nullptr){
        head=newnode;
        tail=newnode;
        }
        else {
        tail->next=newnode;
        tail=newnode;
        }
        if (cin.peek()=='\n') break;
    }
    printy(head);
    cout << "enter the value to be inserted : ";
    int val;
    cin >> val;
    cout << "enter the position to insert the value : ";
    int pos;
    cin >> pos;
    head=insertval(head,val,pos);
    printy(head);
return 0;
}
