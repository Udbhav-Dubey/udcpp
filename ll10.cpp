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
void printy(Node * head){
    Node* curr=head;
    while(curr!=NULL){
        cout << curr->data << "-";
        curr=curr->next;
    }
    cout << endl;
}
int main (){
    cout << "fill the linked list :";
    int x;
    Node* head=nullptr;
    Node* tail=nullptr;
    while(cin>>x){
        Node* newnode= new Node(x);
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
    int vae; // value at end;
    cout << "please enter the value to be inserted to the end";
    cin >> vae;
    Node *atend= new Node(vae);
    tail->next=atend;
    atend->next=nullptr;
    tail=atend;
    printy(head);
return 0;
}
