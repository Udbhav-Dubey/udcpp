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
void printy(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout << curr->data << "-" ;
        curr=curr->next;
    }
    cout << "\n";
}
int main (){
    cout << "enter the numbers of nodes : ";
    int n;
    cin>>n;
    Node *head=nullptr;
    Node *tail=nullptr;
    for (int i=0;i<n;i++){
        cout << "enter the element : " ;
        int v;
        cin>>v;
        Node *newnode= new Node(v);
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
    //Node*temp=head;
    head=head->next;
  //  delete temp;
    cout << "after deleting first\n";
    printy(head);
    return 0;
}
