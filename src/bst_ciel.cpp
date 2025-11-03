#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int value) {
        key = value;
        left = right = nullptr;
    }
};
int findCeil(Node* root, int input) {
    if (root==nullptr){return -1;}
    if (root->key==input){
        return root->key;
    }
    if (root->key<input){
        return findCeil(root->right,input);
    }
    int ceil=findCeil(root->left,input);
    return (ceil>=input)?ceil:root->key;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    for (int i = 0; i < 16; i++)
        cout << i << " " << findCeil(root, i) << endl;

    return 0;
}
