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
Node *delend(Node *head){
    if (head==nullptr){return nullptr;}
    if (head->next==nullptr){delete head; return nullptr;}
    Node *secondlast=head;
    while(secondlast->next->next!=NULL){
        secondlast=secondlast->next;
    }
    delete(secondlast->next);
    secondlast->next=nullptr;
    return head;
}
void printy(Node *head){
    Node * curr=head;
    while(curr!=NULL){
        cout << curr->data << "-" ;
        curr=curr->next;
    }
    cout << endl;
}
int main(){
  int x;
  Node *head=nullptr;
  Node *tail=nullptr;
  cout << "enter the elements of linked list : ";
  while(cin>>x){
    Node *newnode= new Node(x);
    if (head==nullptr){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
    if (cin.peek()=='\n') break;
  }
    printy(head);
    head=delend(head);
    printy(head);
return 0;
}
