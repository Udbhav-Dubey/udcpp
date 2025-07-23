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
void printlist(Node* head){
    Node* current =head;
    while(current!=nullptr){
        cout << current->data << "->";
        current=current->next;
    }
    cout << "NULL\n";
}
int main (){
    Node* node1=new Node(10);
    Node* node2=new Node(20);
    Node* node3=new Node(30);
    node1->next=node2;
    node2->next=node3;
    Node* head = node1;
    printlist(head);
return 0;
}
