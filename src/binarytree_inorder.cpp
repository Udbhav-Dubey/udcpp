#include <iostream>
struct Node{
    int data;
    struct Node*left,*right;
    Node(int v){
        data=v;
        left=right=nullptr;
    }
};
void printInorder(struct Node* node){
    if (node==nullptr){
        return ;
    }
    printInorder(node->left);
    std::cout << node->data<< " ";
    printInorder(node->right);
}
int main (){
    struct Node*root=new Node(1);
    root->left=new Node(2);
    root->left=new Node(3);
    root->left->right=new Node(4);
    root->left->left=new Node(5);
    root->right->right=new Node(6);
    printInorder(root);
    return 0;
}
