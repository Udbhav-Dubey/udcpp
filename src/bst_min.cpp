#include <iostream>
#include<vector>
#include<unordered_map>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
int minValue(Node*root){
    if (root->left==nullptr){return root->data;}
    return minValue(root->left);
}
void inorder(Node*root){
    if (root==nullptr){return ;}
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    std::cout << minValue(root);
    return 0;
}
