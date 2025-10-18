#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next=nullptr;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
void printy(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout << " " << curr->data;
        curr=curr->next;
    }
    cout<<endl;
}
int main (){
    cout << "enter the number of nodes : ";
    int n;
    cin>>n;
    Node *head=nullptr;
    Node *tail=nullptr;
    for (int i=0;i<n;i++){
        cout << "insert for " << i+1<<":";
        int x=0;
        cin>>x;
        Node *newnode=new Node(x);
        if (head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else {
            tail->next=newnode;
            tail=newnode;
        }
    }
    printy(head);
    int vaf;//val at front 
    cout << "enter the value to be inserted at the front : ";
    cin >> vaf;
    Node *frontnode=new Node(vaf);
    frontnode->next=head;
    head=frontnode;
    printy(head);
return 0;
}
