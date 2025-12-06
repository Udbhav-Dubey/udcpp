#include <bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node*left;
    Node*right;
    Node(int val){
        key=val;
        left=nullptr;
        right=nullptr;
    }
};
Node*insertNode(Node*root,int key){
    if (root==nullptr){return new Node(key);}
    if (key<root->key){
        root->left=insertNode(root->left,key);
    }
    else if (key>root->key){
        root->right=insertNode(root->right,key);
    }
    return root;
}
Node*deleteNode(Node*root,int key){
    if (root==nullptr){return root;}
    if (key<root->key){
        root->left=deleteNode(root->left,key);
    }
    else if (key>root->key){
        root->right=deleteNode(root->right,key);
    }
    else{
        if (root->left==nullptr){
            Node*temp=root->right;
            delete root;
            return temp;
        }
        Node*temp=findMin(root->right);
        root->key=temp->key;
        root->right=deleteNode(root->right,temp->key);
    }
    return root;
}
void inorder(Node*root){
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}
int main (){

return 0;
}
