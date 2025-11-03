#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
int findParent(Node*root,int target,int parent){
    if (root==nullptr){
        return -1;
    }
    if (root->data==target){
        return parent;
    }
    int leftsearch=findParent(root->left,target,root->data);
    if (leftsearch!=-1){
        return leftsearch;
    }
    return findParent(root->right,target,root->data);
}
int main() {
  
    // Representation of the given tree
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int target = 3; 
 
    int parent = findParent(root, target, -1);

    cout << parent << endl;

    return 0;
}
