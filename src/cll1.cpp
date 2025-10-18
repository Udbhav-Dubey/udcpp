#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void printCircular(Node* head) {
    if (head == nullptr) return;
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int x;
    cout << "Enter space-separated values (press Enter to stop): ";
    while (cin >> x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (cin.peek() == '\n') break;
    }

    if (tail) tail->next = head;  

    cout << "Circular List: ";
    printCircular(head);

    return 0;
}

