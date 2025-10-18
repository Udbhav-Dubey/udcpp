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
Node*insertatpos(Node*head,Node*&tail,int el,int pos){
    Node*newnode=new Node(el);
    Node*curr=head;
    if (pos==0){
        newnode->next=head;
        tail->next=newnode;
        head=newnode;
        return head;
    }
    int idx=0;
    do{
        idx++;
        curr=curr->next;
        
    }while(idx<pos-1&&curr!=head);
    if (idx < pos - 1) {
    cout << "Invalid position\n";
    delete newnode;
    return head;
}
    if (curr==tail){
        curr->next=newnode;
        newnode->next=head;
        tail=newnode;
        return head;
    }
    Node*temp=curr->next;
    curr->next=newnode; 
    newnode->next=temp;
    return head;
}
void printy(Node*head){
    Node*curr=head;
    do{
        cout<<curr->data<<"-";
        curr=curr->next;
    }while(curr!=head);
    cout<<endl;
}
int main(){
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
    cout << "enter the new position and element respectivelly \n";
    int pos,el;
    cout << "enter the position : ";
    cin >>pos;
    cout << "enter the element : ";
    cin>>el;
    head=insertatpos(head,tail,el,pos);
    printy(head);
return 0;
}
