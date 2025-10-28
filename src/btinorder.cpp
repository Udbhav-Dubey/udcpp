#include <iostream>
#include <vector>
class Node{
public:
    int data;
    Node*lchild;
    Node*rchild;
    Node(int x){
        this->data=x;
        lchild=nullptr;
        rchild=nullptr;
    }
};
void inOrder(Node*node,std::vector<int>&res){
    if (node==nullptr){
        return ;
    }
    inOrder(node->lchild,res);
    res.push_back(node->data);
    inOrder(node->rchild,res);
}
int main (){
    Node*root=new Node(1);
    root->lchild=new Node(2);
    root->rchild=new Node(3);
    root->lchild->lchild= new Node(4);
    root->lchild->rchild=new Node(5);
    root->rchild->rchild=new Node(6);
    std::vector<int> res;
    inOrder(root,res);
    for (int node:res){
        std::cout << node << " "; 
    }
    return 0;
}
