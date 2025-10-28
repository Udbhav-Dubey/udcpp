#include <iostream>
class Node{
    public:
        int val;
        Node*right;
        Node*left;
    Node(int data):val(data),right(nullptr),left(nullptr){}
};
void inorder(Node*root){
    if (root==nullptr){return ;}
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}
int getLevel(Node*root,int key){
    if (root==nullptr){return -1;}
    queue<Node*>q;
    q.push(root);
    int level=1;
    while(q.empty()){
        int size=q.size();
        for (int i=0;i<size;i++){
            Node*curr=q.front();
            q.pop();
            if (curr->data==target){
                return level;
            }
            if (curr->left!=nullptr){
                q.push(curr->left);
            }
            if (curr->right!=nullptr){
                q.push(curr->right);
            }
        }
        level++;
    }
    return -1;
}
int main (){
     // Creating a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7
    Node*root=new Node(1);
   root->right=new Node(3);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    std::cout << "inorder " << std::endl;
    inorder(root);
    std::cout << "\nplease enter node to find its level: ";
    int x;
    std::cin>>x;
    std::cout << getLevel(root,x) << std::endl;
    return 0;
}
