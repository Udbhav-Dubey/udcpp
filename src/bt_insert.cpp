#include <iostream>
#include <queue>
class Node{
    public:
        int val;
        Node*lchild,*rchild;
        Node(int data):val(data),lchild(nullptr),rchild(nullptr) {}
};
Node*insert(Node*root,int key){
    if (root==nullptr){root=new Node(key);return root;}
    std::queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*curr=q.front();
        q.pop();
        if (curr->lchild!=nullptr){
            q.push(curr->lchild);
        }
        else {
            curr->lchild==new Node(key);    
            return root;
        }
        if (curr->rchild!=nullptr){
            q.push(curr->rchild);
        }
        else {
            curr->rchild=new Node(key);
            return root;
        }
    }
    return root;
}
void inOrderTraversal(Node*root){
    if (root==nullptr){return ;}
    inOrderTraversal(root->lchild);
    std::cout << root->val << " ";
    inOrderTraversal(root->rchild);
}
int main (){
// Constructing the binary tree
  	//          10
    //        /    \ 
    //       11     9
    //      /      / \
    //     7      15   8
    Node*root=new Node(10);
    root->lchild=new Node(11);
    root->rchild=new Node(9);
    root->lchild->lchild=new Node(7);
    root->rchild->lchild= new Node(15);
    root->rchild->rchild= new Node(8);
    inOrderTraversal(root);
    std::cout << "\nenter the value to insert in tree : ";
    int x;
    std::cin>>x;
    root=insert(root,x);
    std::cout << " after inserting \n";
    inOrderTraversal(root);
    return 0;
}
