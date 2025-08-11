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
void findkey(Node*head,int el){
    Node*curr=head;
    if (!head){"empty list\n";return ;}
    int idx=0;
    do {
        if (curr->data==el){
            cout << "found at position (0-based):" << idx << endl;
            return ;}
    idx++;    
    curr=curr->next;
    } while(curr!=head);
        cout << "not found";
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
        if (cin.peek()=='\n'){ break;}
    }
    tail->next=head;
    cout << "enter the element to find it : ";
    int el;
    cin>>el;
    findkey(head,el);
return 0;
}
