#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next,*prev;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
void printy(Node*head){
    Node*curr=head;
    do {
        cout<<curr->data <<"-";
        curr=curr->next;
    }while(curr!=head);
    cout <<endl;
}
int main (){
    Node*head=nullptr;
    Node*tail=nullptr;
    cout << "enter the number of nodes : ";
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        Node*newnode=new Node(x);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    tail->next=head;
    printy(head);
    cout << "enter the value at new node : ";
    int val;
    cin>>val;
    Node*newnode=new Node(val);
    newnode->next=head;
    tail->next=newnode;
    head=newnode;
    printy(head);
return 0;
}
