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
Node*insertatend(Node*tail,int value){
    Node*newnode=new Node(value);
    if(tail==nullptr){tail=newnode;newnode->next=newnode;}
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
        return tail;
    }
void printy(Node*head){
    Node*curr=head;
    do{
        cout << curr->data << "-";
        curr=curr->next;
    }while(curr!=head);
    cout<<endl;
}
int main (){
    Node*head=nullptr;
    Node*tail=nullptr;
    int x;
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
    insertatend(tail,69);
    printy(head);
return 0;
}
