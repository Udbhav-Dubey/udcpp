#include <iostream>
#include <vector>
class Node{
public:
    int data;
    Node*lchild,*rchild;
    Node(int value):data(value),lchild(nullptr),rchild(nullptr){}
};
void levelOrderhelp(Node*root,int level,std::vector<std::vector<int>>&res){
    if (root==nullptr){return ;}
    if (res.size()<=level){
        res.push_back({});
    }
    res[level].push_back(root->data);
    levelOrderhelp(root->lchild,level+1,res);
    levelOrderhelp(root->rchild,level+1,res);
}
std::vector<std::vector<int>> levelOrder(Node*root){
    std::vector<std::vector<int>>res;
    levelOrderhelp(root,0,res);
    return res;
}
 int main (){
    Node*root=new Node(5);
    root->lchild=new Node(12);
    root->rchild=new Node(13);
    root->lchild->lchild= new Node(7);
    root->lchild->rchild= new Node(14);
    root->rchild->rchild=new Node(2);
    root->lchild->lchild->lchild=new Node(17);
    root->lchild->lchild->rchild=new Node(23);
    root->lchild->rchild->lchild= new Node(27);
    root->lchild->rchild->rchild= new Node(3);
    root->rchild->rchild->lchild= new Node(8);
    root->rchild->rchild->rchild= new Node(11);
    std::vector <std::vector<int>>res=levelOrder(root);
    for (std::vector<int>level:res){
        for (int val:level){
            std::cout << val <<" ";
        }
        std::cout << std::endl;
    }
    return 0;
}   
