#include <iostream>
#include <vector>
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
void postOrder(Node*node,std::vector<int>&res){
    if (node==nullptr){
        return ;
    }
    postOrder(node->lchild,res);
    postOrder(node->rchild,res);
    res.push_back(node->data);
}
int main (){
    Node*root=new Node(1);
    root->lchild=new Node(2);
    root->rchild=new Node(3);
    root->lchild->lchild= new Node(4);
    root->lchild->rchild= new Node(5);
    root->rchild->rchild= new Node(6);
    std::vector <int> res;
    postOrder(root,res);
    for (int val:res){
        std::cout<<val<<" ";
    }
    return 0;
}
