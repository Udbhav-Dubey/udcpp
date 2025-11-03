#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
void printLeafNodes(Node*root){
    if (!root)return ;
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        if (!root->left&&!root->right){
            cout << root->data<<" ";
        }
        if (root->right){
            st.push(root->right);
        }
        if (root->left){
            st.push(root->left);
        }
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    printLeafNodes(root);    
    return 0;
}
