#include <iostream>
class Node{
    public:
        int data;
        Node*rchild;
        Node*lchild;
        Node(int x){
            this->data=x;
            rchild=nullptr;
            lchild=nullptr;
        }
};
int height(Node*root){
    if (root==nullptr){return -1;}
    int lHeight=height(root->lchild);
    int rHeight=height(root->rchild);
    return std::max(lHeight,rHeight)+1;
}
int main (){
    Node*root=new Node(12);
    root->lchild=new Node(8);
    root->rchild=new Node(18);
    root->lchild->lchild=new Node(5);
    root->lchild->rchild=new Node(11);
    std::cout << height(root);
    return 0;
}
