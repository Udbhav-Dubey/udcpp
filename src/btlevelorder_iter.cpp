#include <iostream>
#include <vector>
#include <queue>
class Node{
public:
    int data;
    Node*rchild;
    Node*lchild;
    Node(int x){
        data=x;
        rchild=nullptr;
        lchild=nullptr;
    }
};
std::vector<std::vector<int>>levelOrder(Node*root){
    if (root==nullptr){
        return {};
    }
    std::queue<Node*>q;
    std::vector<std::vector<int>>res;
    q.push(root);
    int currlevel=0;
    while(!q.empty()){
        int len=q.size();
        res.push_back({});
        for (int i=0;i<len;i++){
            Node*node=q.front();
            q.pop();
            res[currlevel].push_back(node->data);
            if (node->lchild!=nullptr){
                q.push(node->lchild);
            }
            if (node->rchild!=nullptr){
                q.push(node->rchild);
            }}
            currlevel++;
    }
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

    for (std::vector<int> level:res){
        for (int val:level){
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
