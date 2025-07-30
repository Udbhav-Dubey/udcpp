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
int findLength(Node *head){
    if (head==NULL){
        return 0;
    }
    return 1+findLength(head->next);
}
int main (){
    cout << "please enter the elements : ";
    int x;
    Node *head=nullptr;
    Node *tail=nullptr;
    while(cin>>x){
        Node *newNode = new Node(x);
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
    cout << "your length is " << findLength(head);
return 0;
}
