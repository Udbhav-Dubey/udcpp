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
void printlist(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout << temp->data << "->" ;
        temp=temp->next;
    }
    cout << "Null\n";
}
int main (){
    cout << "enter the elements of linked list in one line by spaces\n";
    int x;
    Node* head=nullptr;
    Node* tail=nullptr;
    while(cin>>x){
        Node* newNode=new Node(x);
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
    cout << "linked list:";
    printlist(head); 
    return 0;
}
