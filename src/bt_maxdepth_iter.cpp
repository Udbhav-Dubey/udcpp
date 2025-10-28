#include <iostream>
#include <queue>
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
    if (root==nullptr){
        return 0;
    }
    std::queue<Node*>q;
    q.push(root);
    int depth=0;
    while(!q.empty()){
        int len=q.size();
        for (int i=0;i<len;i++){
            Node*curr=q.front();
            q.pop();
            if (curr->lchild){q.push(curr->lchild);}
            if (curr->rchild){q.push(curr->rchild);}
        }
        depth++;
    }
    return depth-1;
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
