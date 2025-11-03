#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;    
  
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int floor(Node* root, int x) {
    if (root==nullptr){
        return -1;
    }
    if (root->data>x){
        return floor(root->left,x);
    }
    int floorval=floor(root->right,x);
    return (floorval<=x&&floorval!=-1)?floorval:root->data;
}

int main() {
    // Representation of the given tree
    //       10
    //       / \
    //      5  15
    //         / \
    //        12 30 
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(30);

    int x = 14;
    cout << floor(root, x) << endl;
    return 0;
}
