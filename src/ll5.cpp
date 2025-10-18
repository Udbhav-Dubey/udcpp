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
bool searchkey(Node* head,int key){
    Node * curr=head;
    while(curr!=NULL){
        if (curr->data=key){return true;}
        curr=curr->next;
    }
    return false;
}
int main (){
    int x;
    Node *head=nullptr;
    Node *tail=nullptr;
    while(cin>>x){
        Node* newNode= new Node(x);
        if (head==nullptr){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        if (cin.peek()=='\n') break;
    }
    cout << "please enter the key : ";
    int key;
    cin >> key;
    cout << searchkey(head,key);
return 0;
}
