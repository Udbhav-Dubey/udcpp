#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

Node *insertInEmptyList(Node *last, int data){
    if (last != nullptr) return last;
    
    Node *newNode = new Node(data);
  
    newNode->next = newNode;
  
    last = newNode;
    return last;
}

void printList(Node* last){
    if(last == NULL) return;
  
    Node* head = last->next;
    while (true) {
        cout << head->data << " ";
        head = head->next;
        if (head == last->next) break;
    }
    cout << endl;
}

int main(){
    Node *last = nullptr;

    last = insertInEmptyList(last, 1);

    cout << "List after insertion: ";
    printList(last);

    return 0;
}
