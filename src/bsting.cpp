#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node*left;
        Node*right;
        Node(int val){
            data=val;
            left=nullptr;
            right=nullptr;
        }
};
void preorder(Node*root){
    if (!root){return ;}
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node*root){
    if (!root){return ;}
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void inorder(Node*root){
    if (!root){return ;}
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node*insert(Node*root,int val){
    if (!root){return new Node(val);}
    if (root->data>val){root->left=insert(root->left,val);}
    else {root->right=insert(root->right,val);}
    return root;
}
Node*getSuccessor(Node*root){
    root=root->right;
    while(root&&root->left){
        root=root->left;
    }
    return root;
}
Node*delNode(Node*root,int x){
    if (!root){return nullptr;}
    if (x<root->data){
        root->left=delNode(root->left,x);
    }
    else if (x>root->data){
        root->right=delNode(root->right,x);
    }
    else {
        if (!root->left){
            Node*temp=root->right;
            delete root;
            return temp;
        }
        if (!root->right){
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
int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder: ";
    inorder(root);
    cout << "\n";

    root = delNode(root, 70);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << "\n";

    return 0;
}
