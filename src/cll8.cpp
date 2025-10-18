#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
Node*delatend(Node*&head,Node*&tail){
    if (tail==nullptr){
        cout << "empty";
        return nullptr;
    }
    if (head==tail){
        delete head;
        head=tail=nullptr;
        return nullptr;
    }
    Node*curr=head;
    while(curr->next!=tail){
        curr=curr->next;
    }
    curr->next=head;
    tail=curr;
    return head;
}
void printy(Node*head){
       if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    Node*curr=head;
    do{
        cout << curr->data << "-";
        curr=curr->next;
    }
    while(curr!=head);
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
            tail=newnode;
        }
        if (cin.peek()=='\n') break;
    }
    tail->next=head;
    printy(head);
    head=delatend(head,tail);
    printy(head);
return 0;
}
