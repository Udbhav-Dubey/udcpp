//Driver Code Starts
#include <iostream>
#include<vector>
#include<unordered_map>
#include <queue>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
Node*getSuccessor(Node*curr){
    curr=curr->right;
    while(curr!=nullptr&&curr->left!=nullptr){
        curr=curr->left;}
        return curr;
    }

Node*delNode(Node*root,int x){
    if (root==nullptr){
        return nullptr;
    }
    if (x<root->data){
        root->left=delNode(root->left,x);
    }
    else if (x>root->data){
        root->right=delNode(root->right,x);
    }
    else {
        if (root->left==nullptr){
            Node*temp=root->right;
            delete root;
            return temp;
        }
        if (root->right==nullptr){
            Node*temp=root->left;
            delete root;
            return temp;
        }
        Node*succ=getSuccessor(root);
        root->data=succ->data;
        root->right=delNode(root->right,succ->data);
    }
    return root;
}
void inorder(Node*root){
    if (root==nullptr){return ;}
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    int x = 15;
    root = delNode(root, x);

    inorder(root);
    return 0;
}
