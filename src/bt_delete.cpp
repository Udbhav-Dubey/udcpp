#include <iostream>
#include <queue>
class Node{
public:
    int data;
    Node*lchild,*rchild;
    Node(int data):data(data),lchild(nullptr),rchild(nullptr){}
};
void inorder(Node*root){
    if (root==nullptr){return ;}
    inorder(root->lchild);
    std::cout << root->data << " ";
    inorder(root->rchild);
}
void deletDeepest(Node*root,Node*dNode){
    std::queue<Node*>q;
    q.push(root);
    Node*curr=nullptr;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        if (curr->lchild){
            if (curr->lchild==dNode){
                delete curr->lchild;
                curr->lchild=nullptr;
                return ;
            } else q.push(curr->lchild);
        }
        if (curr->rchild){
            if (curr->rchild==dNode){
                delete curr->rchild;
                curr->rchild=nullptr;
                return ;
            } else q.push(curr->rchild);
        }
    }
}
Node*DeletNode(Node*root,int key){
    if (root==nullptr){
        return nullptr;
    }
    else if (root->lchild==nullptr&&root->rchild==nullptr){
        if (root->data==key){
            delete root;
            return nullptr;
        }
        else return root;
    }
    std::queue<Node*> q;
    q.push(root);
    Node*curr=nullptr;
    Node*keyNode=nullptr;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        if (curr->data==key){
            keyNode=curr;
        }
        if (curr->lchild){
            q.push(curr->lchild);
        }
        if (curr->rchild){
            q.push(curr->rchild);
        }
        }
    if (keyNode!=nullptr){
        int x=curr->data;
        keyNode->data=x;
        deletDeepest(root,curr);
    }   
return root;
}
int main (){
    // Construct the binary tree
    //       10         
  	//      /  \       
  	//    11    9
  	//   / \   / \     
  	//  7  12 15  8     

    Node*root=new Node(10);
    root->lchild=new Node(11);
    root->rchild=new Node(9);
    root->lchild->lchild= new Node(7);
    root->lchild->rchild= new Node(12);
    root->rchild->lchild= new Node(15);
    root->rchild->rchild= new Node(8);
    while(root){
    inorder(root);
    std::cout << "\ninsert element to delete : ";
    int x;
    std::cin >>  x;
    root=DeletNode(root,x);
    std::cout << "after deletion : \n";
    inorder(root);
    std::cout << "\n";
    }
  return 0;  
}
