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
void traverselist(Node* head){
    if (head==nullptr){
        cout << "NULL";
        return;
    }
    cout << head->data << "->";
    traverselist(head->next);
}
int main (){
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    traverselist(head);
return 0;
}
