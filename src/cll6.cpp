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
        cout<<curr->data<<"-";
        curr=curr->next;
    }while(curr!=head);
    cout<<endl;
}
Node*delhead(Node*head,Node*tail){
    if (head==nullptr){return nullptr;}
        if (head == tail) {
        delete head;
        return nullptr;
    }
    tail->next=head->next;
    head=head->next;
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
    head=delhead(head,tail);
    printy(head);
return 0;
}
