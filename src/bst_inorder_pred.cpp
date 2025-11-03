#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* rightmost(Node* node) {
    while(node->right!=nullptr){
        node=node->right;
    }
    return node;
}
Node* getPred(Node* root, int target){
    if (root==nullptr){return nullptr;}
    Node*pred=nullptr;
    Node*curr=root;
    while(curr!=nullptr){
        if (target>curr->data){
            pred=curr;
            curr=curr->right;
        }
        else if (target<curr->data){
            curr=curr->left;
        }
        else {
            if (curr->left!=nullptr){
                return rightmost(curr->left);
            }
            break;
        }
    }
    return pred;
} 

int main() {
  
    // Construct a BST
    //            20
    //          /    \
    //         8      22
    //       /   \
    //      4    12
    //          /  \
    //         10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
  
    int target = 12;
    Node* pred = getPred(root, target);
    if (pred != nullptr)
        cout << pred->data;
    else
        cout << "null";
    return 0;
}
