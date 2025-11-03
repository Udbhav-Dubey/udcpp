#include <iostream>
class Node{
    public:
        int data;
        Node*left;
        Node*right;
        Node(int x){
            data=x;
            left=nullptr;
            right=nullptr;
        }
};
Node*insert(Node*root,int key){
    if (root==nullptr){return new Node(key);}
    if (key<root->data){
        root->left=insert(root->left,key);}
    else {root->right=insert(root->right,key);}
    return root;
}
void inorder(Node*root){
    if (root==nullptr){
        return ;
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
int main (){
    Node* root = nullptr;

    // Create BST
    //       22
    //      /  \
    //     12   30
    //     / \   
    //    8  20
    //       / \
    //      15  30

    root = insert(root, 22);
    root = insert(root, 12);
    root = insert(root, 30);
    root = insert(root, 8);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);
    inorder(root);
}
