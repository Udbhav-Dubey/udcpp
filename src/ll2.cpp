#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
void printlist(Node *head){
    Node* temp=head;
    while(temp!=nullptr){
        cout << temp->data << "->" ;
        temp=temp->next;
    }
    cout << "NULL";
}
int main (){
    int n;
    cout << "number of nodes?";
    cin>>n;
    Node *head=nullptr;
    Node *tail=nullptr;
    for (int i=0;i<n;i++){
        int val;
        cout << "enter value for node :"<< i+1 << ":";
        cin >> val;
        Node *newNode= new Node(val);
        if (head==nullptr){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    cout << "linked list :" << endl;
    printlist(head);
}
