#include <iostream>
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
    do{
        cout << curr->data << "-";
        curr=curr->next;
    }while(curr!=head);
    cout << endl;
}
Node*delatpos(Node*head,Node*&tail,int pos){
    Node*curr=head;
    if (pos==0){
        tail->next=head->next;
        head=head->next;
        return head;
    }
    int idx=0;
    do {
        idx++;
        curr=curr->next;
    }while(idx<pos-1&&curr->next!=head);
    if (curr->next==head){cout << "invalid position ";}
    Node*temp=curr->next;
    curr->next=temp->next;
    delete temp;
    return head;
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
            tail=newnode;
        }
        if (cin.peek()=='\n') break;
    }
    tail->next=head;
    printy(head);
    cout << "enter the pos to delete : ";
    int pos;
    cin>>pos;
    head=delatpos(head,tail,pos);
    printy(head);
return 0;
}
