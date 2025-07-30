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
void printy(Node*head){
    Node *curr=head;
    while(curr!=NULL){
        cout << curr->data << "-" ;
        curr=curr->next;
    }
    cout << endl;
}
Node *delpos(Node *head,int pos){
    Node *prev;
    Node *temp=head;
    if (head==NULL){
        return head;
    }
    if (pos==1){
        head=temp->next;
        free(temp);
        return head;
    }
    for (int i=1;i!=pos;i++){
        prev=temp;
        temp=temp->next;
    }
    if (temp!=NULL){
        prev->next=temp->next;
        free(temp);
    }
    else {cout << "data not present \n";}
    return head;
}
int main(){
    int n;
    cout<< "enter the number of nodes : ";
    cin >>n;
    Node *head=nullptr;
    Node *tail=nullptr;
    for (int i=0;i<n;i++){
        int val;
        cout << "enter the element : ";
        cin >> val;
        Node *newnode=new Node(val);
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
    cout << "enter the position to be deleted : ";
    int pos ; // value to delete
    cin >> pos;
    head=delpos(head,pos);
    printy(head);
return 0;
}
