#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
bool searchkey(Node* head,int key){
    if (head==NULL){return false;}
    if (head->data==key){return true;}
    return searchkey(head->next,key);
}
int main (){
    cout << "please tell number of nodes : " << endl;
    int n;
    cin>>n;
    Node* head=nullptr;
    Node* tail=nullptr;
    for (int i=0;i<n;i++){
        int val;
        cout << "enter the value : ";
        cin >> val;
        Node* newNode=new Node(val);
        if (head==nullptr){
            head=newNode;
            tail=newNode;
        }
        else {
            tail->next=newNode;
            tail=newNode;
        }
    }
    cout << "enter the key:";
    int key;
    cin >> key;
    cout << searchkey(head,key);
return 0;
}
