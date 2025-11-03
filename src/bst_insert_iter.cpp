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
    Node*temp=new Node(key);
    if (root==nullptr){
        return temp;
    }
    Node*curr=root;
    while(curr!=nullptr){
        if (curr->data>key&&curr->left!=nullptr){
            curr=curr->left;
        }
        else if (curr->data<key&&curr->right!=nullptr){
            curr=curr->right;
        }
        else break;
    }
    if (curr->data>key){
        curr->left=temp;
    }
    else curr->right=temp;
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
