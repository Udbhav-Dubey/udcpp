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
void printy(Node*head){
    Node*curr=head;
    while(curr!=nullptr){
        cout << curr->data << "-";
        curr=curr->next;
    }
    cout << endl;
}
void deletelinkedlist(Node*&head){
    while(head!=nullptr){
        Node*temp=head->next;
        delete head;
        head=temp;
    }
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
        }
        if (cin.peek()=='\n'){break;}
    }
    printy(head);
    deletelinkedlist(head);
    printy(head);
return 0;
}
