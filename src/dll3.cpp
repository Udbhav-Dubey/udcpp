#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next=nullptr;
    Node*prev=nullptr;
    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
void reverseprinty(Node*tail){
    Node*curr=tail;
    while(curr!=nullptr){
        cout << curr->data<<"-";
        curr=curr->prev;
    }
    cout << endl;
}
int main (){
    cout << "enter the elements by spacing : ";
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
            newnode->prev=tail;
            tail=newnode;
        }
        if (cin.peek()=='\n' ) break;
    }
reverseprinty(tail);
return 0;
}
